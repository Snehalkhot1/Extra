function login() {
    window.location.href = "dashboard.html";
}

function checkMood() {

    let mood = document.getElementById("mood").value;

    let result = document.getElementById("moodResult");

    if (mood.includes("Happy")) {

        result.innerHTML = `
<div style="margin-top:20px;color:lightgreen;">
🚀 Amazing! Keep maintaining your positive energy.
</div>`;
    } else if (mood.includes("Neutral")) {

        result.innerHTML = `
<div style="margin-top:20px;color:orange;">
😊 Stay motivated and take small breaks.
</div>`;
    } else {

        result.innerHTML = `
<div style="margin-top:20px;color:red;">
⚠️ High stress detected. Relax and refresh.
</div>`;
    }
}

const ctx = document.getElementById('chart');

if (ctx) {

    new Chart(ctx, {

        type: 'line',

        data: {
            labels: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'],

            datasets: [{
                label: 'Performance',
                data: [65, 80, 75, 90, 85, 95],
                borderColor: 'cyan',
                backgroundColor: 'rgba(0,255,255,0.1)',
                tension: 0.4,
                fill: true
            }]
        }

    });

}