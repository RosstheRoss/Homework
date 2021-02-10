var iconImg;

function randImage() {
    var index = Math.floor(Math.random()*7);
    
    var pictures = ["CPE", "EPT", "GPP", "GUI", "PERF", "PORT", "SEO"];
    var descriptions = ["Common Programming Error",
        "Error-Prevention Tip", "Good Programming Practice",
        "Look-and-Feel Observation", "Performance Tip", "Portability Tip",
        "Software Engineering Observation"];
    
    iconImg.src = pictures[index] + ".png";
    iconImg.alt = descriptions[index]; 
}

function start() {
    iconImg = document.getElementById("image");
    iconImg.addEventListener("click", randImage, false);
}

window.addEventListener("load", start);