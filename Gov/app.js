const schemesSection = document.getElementById("schemesSection");
const ratesSection = document.getElementById("ratesSection");

const schemesContainer = document.getElementById("schemesContainer");
const ratesContainer = document.getElementById("ratesContainer");


function showSchemes() {

    ratesSection.classList.add("hidden");

    schemesSection.classList.remove("hidden");

    renderSchemes();

}


function showRates() {

    schemesSection.classList.add("hidden");

    ratesSection.classList.remove("hidden");

    renderRates();

}


function renderSchemes() {

    schemesContainer.innerHTML = "";

    schemes.forEach(scheme => {

        const card = document.createElement("div");

        card.className = "scheme-card fade-in";

        card.innerHTML = `

<h3>📜 ${scheme.name}</h3>

<p>${scheme.description}</p>

<a href="${scheme.link}" target="_blank">Read More</a>

`;

        schemesContainer.appendChild(card);

    });

}


function renderRates() {

    ratesContainer.innerHTML = "";

    cropRates.forEach(item => {

        const row = document.createElement("tr");

        row.innerHTML = `

<td>🌾 ${item.crop}</td>

<td>${item.market}</td>

<td>₹ ${item.price}</td>

`;

        ratesContainer.appendChild(row);

    });

}