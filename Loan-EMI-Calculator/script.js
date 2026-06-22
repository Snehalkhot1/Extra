// LOGIN FUNCTION
function login() {
    let user = document.getElementById("username").value;
    let pass = document.getElementById("password").value;

    if (user === "admin" && pass === "1234") {
        localStorage.setItem("login", "true");
        window.location.href = "dashboard.html";
    } else {
        alert("Invalid Login");
    }
}

// LOGOUT
function logout() {
    localStorage.removeItem("login");
    window.location.href = "login.html";
}

// CHECK LOGIN (for dashboard)
if (window.location.pathname.includes("dashboard.html")) {
    if (localStorage.getItem("login") !== "true") {
        window.location.href = "login.html";
    }
}

// EMI CALCULATION
let chart;

function calculateEMI() {
    let P = document.getElementById("amount").value;
    let R = document.getElementById("rate").value / 12 / 100;
    let N = document.getElementById("time").value * 12;

    if (P === "" || R === "" || N === "") {
        alert("Enter all values");
        return;
    }

    let EMI = (P * R * Math.pow(1 + R, N)) /
        (Math.pow(1 + R, N) - 1);

    EMI = EMI.toFixed(2);

    let total = (EMI * N).toFixed(2);
    let interest = (total - P).toFixed(2);

    document.getElementById("result").innerHTML =
        "EMI: ₹ " + EMI + "<br>" +
        "Total Payment: ₹ " + total + "<br>" +
        "Interest: ₹ " + interest;

    drawChart(P, interest);
}

// GRAPH
function drawChart(principal, interest) {
    let ctx = document.getElementById("chart");

    if (chart) chart.destroy();

    chart = new Chart(ctx, {
        type: "pie",
        data: {
            labels: ["Principal", "Interest"],
            datasets: [{
                data: [principal, interest],
                backgroundColor: ["green", "red"]
            }]
        }
    });
}