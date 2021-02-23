function change(small, row) {
    document.getElementsByClassName("smol")[row].src = small;
}
function lucky() {
    var image = ["carlson.jpg", "johnston.jpg", "morrill.jpg", "shepherd.jpg", "snyder.jpg", "walter.jpg"];
    document.getElementById("bigboi").src = image[Math.floor(6 * Math.random())];
}
let map;
function initMap() {
    map = new google.maps.Map(document.getElementById("map"), {
        center: { lat: 44.9727, lng: -93.23540000000003 },
        zoom: 14,
    });

    var service = new google.maps.places.PlacesService(map);
    entries = document.getElementsByClassName("entry");
    locations = [];
    for (e=0; e<entries.length; e+=1) {
        var kludge = 0;
        var request = {
            query: entries[e].getElementsByClassName("address")[0].textContent,
            fields: ['name', 'geometry'],
        };
        service.findPlaceFromQuery(request, function (results, status) {
            if (status === google.maps.places.PlacesServiceStatus.OK) {
                locations[kludge++] = results[0];
            }
            if (kludge == entries.length) {
                addPoints(locations);
            }
        });
    }
}

function addPoints(locations) {
    for (x in locations) {
        newEntry = document.getElementsByClassName("entry")[x];
        var marker = new google.maps.Marker({
            map,
            position: locations[x].geometry.location,
            title: newEntry.getElementsByClassName("name")[0].textContent,
            icon: "./Untitled.png",
            data: {
                content:    "<div class='id'>" + 
                            "<b>" + newEntry.getElementsByClassName("name")[0].textContent + "</b>" + "<br>" +
                            newEntry.getElementsByClassName("category")[0].textContent + "<br>" +
                            newEntry.getElementsByClassName("room")[0].textContent + " " + newEntry.getElementsByClassName("street")[0].textContent + "<br>" +
                            newEntry.getElementsByClassName("city")[0].textContent + 
                            "</div>",
            }
        });
        marker.addListener('click', function () {
            if (!this.infoWindow) {
                this.infoWindow = new google.maps.InfoWindow({
                    content: this.data.content,
                    
                });
            }
            this.infoWindow.open(map, this);
        })
    }
}