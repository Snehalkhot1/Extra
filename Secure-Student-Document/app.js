// Ethereum contract details
const contractAddress = "YOUR_DEPLOYED_CONTRACT_ADDRESS"; // replace after deployment
const contractABI = [{
        "inputs": [
            { "internalType": "string", "name": "docName", "type": "string" },
            { "internalType": "string", "name": "hash", "type": "string" }
        ],
        "name": "storeHash",
        "outputs": [],
        "stateMutability": "nonpayable",
        "type": "function"
    },
    {
        "inputs": [
            { "internalType": "string", "name": "docName", "type": "string" }
        ],
        "name": "getHash",
        "outputs": [
            { "internalType": "string", "name": "", "type": "string" }
        ],
        "stateMutability": "view",
        "type": "function"
    }
];

// Connect to MetaMask
async function connectBlockchain() {
    if (window.ethereum) {
        await window.ethereum.request({ method: "eth_requestAccounts" });
        const provider = new ethers.providers.Web3Provider(window.ethereum);
        const signer = provider.getSigner();
        return new ethers.Contract(contractAddress, contractABI, signer);
    } else {
        alert("Please install MetaMask to use blockchain features.");
        return null;
    }
}

// Login
document.getElementById("loginForm").addEventListener("submit", async(e) => {
    e.preventDefault();
    const email = document.getElementById("email").value;
    const password = document.getElementById("password").value;

    try {
        await auth.signInWithEmailAndPassword(email, password);
        alert("Login successful! Email notification sent.");
        document.getElementById("uploadSection").style.display = "block";
        // Firebase Function will send email notification
    } catch (error) {
        alert(error.message);
    }
});

// Upload Document
document.getElementById("uploadBtn").addEventListener("click", async() => {
    const file = document.getElementById("documentFile").files[0];
    if (!file) return alert("Please select a file");

    // Upload to Firebase Storage
    const storageRef = storage.ref("documents/" + file.name);
    await storageRef.put(file);

    // Generate SHA-256 hash
    const reader = new FileReader();
    reader.onload = async function(event) {
        const buffer = event.target.result;
        const hashBuffer = await crypto.subtle.digest("SHA-256", buffer);
        const hashArray = Array.from(new Uint8Array(hashBuffer));
        const hashHex = hashArray.map(b => b.toString(16).padStart(2, "0")).join("");
        document.getElementById("hashOutput").innerText = "Document Hash: " + hashHex;

        // Store hash in Firestore
        await db.collection("documents").add({
            name: file.name,
            hash: hashHex,
            uploadedAt: new Date()
        });

        // Store hash on Ethereum
        const contract = await connectBlockchain();
        if (contract) {
            try {
                const tx = await contract.storeHash(file.name, hashHex);
                await tx.wait();
                alert("Hash stored on Ethereum successfully!");
            } catch (err) {
                console.error(err);
                alert("Error storing hash on blockchain.");
            }
        }
    };
    reader.readAsArrayBuffer(file);
});