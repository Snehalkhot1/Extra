const hre = require("hardhat");

async function main() {
    const DocumentStorage = await hre.ethers.getContractFactory("DocumentStorage");
    const contract = await DocumentStorage.deploy();
    await contract.deployed();
    console.log("DocumentStorage deployed to:", contract.address);
}

main().catch((error) => {
    console.error(error);
    process.exitCode = 1;
});