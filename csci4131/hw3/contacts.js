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
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(
            (position) => {
                curLoc = {
                    lat: position.coords.latitude,
                    lng: position.coords.longitude,
                };
            },
            () => {
                alert("Geolocation failed. Directions will not work.");
            }
        )
    }
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
var searchMarker = [];
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
        service = new google.maps.places.PlacesService(map);
        service.textSearch(request, (results, status) => {
            if (status === google.maps.places.PlacesServiceStatus.OK && results) {
                addPointsSearch(results, true);
            }
        });
    }
}

function addPointsSearch(locations, isOther) {
    deleteMarkers();
    for (x in locations) {
        var marker;
        if (isOther) {
            if (google.maps.geometry.spherical.computeDistanceBetween(locations[x].geometry.location, map.getCenter()) < parseInt(otherRadius)) {
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
            marker = new google.maps.Marker({
                map,
                title: locations[x].name,
                position: locations[x].geometry.location,
                data: {
                    content: "<b>" + locations[x].name + "</b>"
                        + "<br>" + locations[x].vicinity
                },
            });
        }
        if (marker) {
            marker.addListener('click', function () {
                if (!this.infoWindow) {
                    this.infoWindow = new google.maps.InfoWindow({
                        content: this.data.content,
                    });
                    this.infoWindow.open(map, this);
                }
            })
            searchMarker.push(marker);
        }
        
    }
}
function deleteMarkers() {
    for (let i = 0; i < searchMarker.length; i++) {
        searchMarker[i].setMap(null);
    }
    searchMarker = [];
}

var curLoc, directionsService, directionsRenderer;
function directions () {
    directionsService = new google.maps.DirectionsService();
    directionsRenderer = new google.maps.DirectionsRenderer();
    document.getElementById("transitList").textContent = "";
    directionsRenderer.setPanel(document.getElementById("transitList"));
    directionsRenderer.setMap(map);
    var selectedMode = document.getElementById('means').value;
    var dest = {
        query: document.getElementById("destination").value,
        fields: ['name', 'geometry'],
    };
    service = new google.maps.places.PlacesService(map);
    service.findPlaceFromQuery(dest, function (results, status) {
        if (status === google.maps.places.PlacesServiceStatus.OK) {
            console.log(results);
            doDirections(results[0]);
        }
    });
}

function doDirections(input) {
    var means;
    var mean = document.getElementsByName('means');
    for (var i = 0; i < mean.length; i++) {
        if (mean[i].checked) {
            means = mean[i].value;
        }
    }
    
    var request = {
        origin: curLoc,
        destination: input.geometry.location,
        // Note that JavaScript allows us to access the constant
        // using square brackets and a string value as its
        // "property."
        travelMode: google.maps.TravelMode[means]
    };
    directionsService.route(request, function (result, status) {
        if (status == 'OK') {
            directionsRenderer.setDirections(result);
        }
    });
}

function initForm() {
    map = new google.maps.Map(document.getElementById("formap"), {
        center: center,
        zoom: 14,
    });
}