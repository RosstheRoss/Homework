function change(big, small, row) {
    // document.getElementById("bigboi").src = big;
    document.getElementById("smol" + row).src = small;
}
function lucky() {
    var image = ["carlson.jpg", "johnston.jpg", "morrill.jpg", "shepherd.jpg", "snyder.jpg", "walter.jpg"];
    document.getElementById("bigboi").src = image[Math.floor(6 * Math.random())];
}
