function login() {
    window.location.href = "dashboard.html";
}

function analyzeSkills() {

    let result = document.getElementById("result");

    result.innerHTML = `
  <div style="margin-top:20px;">

    <h2>Recommended Learning Path</h2>

    <ul style="margin-top:15px; line-height:2;">
      <li>React.js</li>
      <li>Git & GitHub</li>
      <li>REST API Integration</li>
      <li>Responsive UI Design</li>
    </ul>

  </div>
  `;
}

function checkStress() {

    let stress = document.getElementById("stress").value;

    let result = document.getElement