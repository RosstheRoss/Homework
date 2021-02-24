document.getElementById("bigboi").classList.add("isntRotating");

function change(small, row) {
    document.getElementsByClassName("smol")[row].src = small;
}
function lucky() {
    var image = ["carlson.jpg", "johnston.jpg", "morrill.jpg", "shepherd.jpg", "snyder.jpg", "walter.jpg"];
    document.getElementById("bigboi").src = image[Math.floor(6 * Math.random())];
}
let isRotating=0;
function dizzy() {
    if (!isRotating) {
        document.getElementById("bigboi").classList.remove("isntRotating");
    } else {
    	document.getElementById("bigboi").classList.add("isntRotating");
    }
    isRotating^=1;   
}
function check(value) {
    if(value==="Other")
        document.getElementById('others').style.display = 'block';
    else
        document.getElementById('others').style.display = 'none';
}
let map;
var center = { lat: 44.9727, lng: -93.23540000000003 };
function initMap() {
    map = new google.maps.Map(document.getElementById("map"), {
        center: center,
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
                addPointsContacts(locations);
            }
        });
    }
}
function addPointsContacts(locations) {
    for (x in locations) {
        var newEntry = document.getElementsByClassName("entry")[x];
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
            },
        });
        marker.addListener('click', function () {
            if (!this.infoWindow) {
                this.infoWindow = new google.maps.InfoWindow({
                    content: this.data.content,
                });
                this.infoWindow.open(map, this);
            }
        })
    }
}
var service;
var otherRadius;
function searchPlaces() {
    var request;
    if (document.getElementById("places").value!="Other") {
        request = {
            location: center,
            radius: document.getElementById("distance").value,
            type: document.getElementById("places").value,
        };
        service = new google.maps.places.PlacesService(map);
        service.nearbySearch(request, (results, status) => {
            if (status === google.maps.places.PlacesServiceStatus.OK && results) {
                addPointsSearch(results, false);
            }
        });
    } else {
        request = {
            location: center,
            radius: document.getElementById("distance").value,
            query: document.getElementById("others").value,
        };
        otherRadius = request.radius;
        console.log(otherRadius);
        service = new google.maps.places.PlacesService(map);
        service.textSearch(request, (results, status) => {
            if (status === google.maps.places.PlacesServiceStatus.OK && results) {
                addPointsSearch(results, true);
            }
        });
    }
}
function addPointsSearch(locations, isOther) {
    console.log(locations);
    for (x in locations) {
        var marker;
        if (isOther) {
            if (google.maps.geometry.spherical.computeDistanceBetween(locations[x].geometry.location, center) < parseInt(otherRadius)) {
                marker = new google.maps.Marker({
                    map,
                    title: locations[x].name,
                    position: locations[x].geometry.location,
                    data: {
                        content: "<b>" + locations[x].name + "</b>"
                            + "<br>" + locations[x].formatted_address
                    },
                });
            }
        } else {
            var marker = new google.maps.Marker({
                map,
                title: locations[x].name,
                position: locations[x].geometry.location,
                data: {
                    content: "<b>" + locations[x].name + "</b>"
                        + "<br>" + locations[x].vicinity
                },
            });
        }
        
        marker.addListener('click', function () {
            if (!this.infoWindow) {
                this.infoWindow = new google.maps.InfoWindow({
                    content: this.data.content,
                });
                this.infoWindow.open(map, this);
            }
        })
    }
}
