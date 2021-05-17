
const http = require('http');
const url = require('url');
const fs = require('fs');
const qs = require('querystring');

const port = 9001;
http.createServer(function (req, res) {
  var q = url.parse(req.url, true);
  var filename = "." + q.pathname;
  if(req.url === '/'){
    res.writeHead(301, { 'Location': 'index.html' });
    return res.end("301 Permanent Redirect");
  }
  else if (req.url === '/index.html') {
    indexPage(req, res, '/index.html');
  }
  else if (req.url === '/contacts.html') {
    indexPage(req, res, '/contacts.html');
  }
  else if (req.url === '/addContact.html') {
    indexPage(req, res, '/addContact.html');
  }
  else if (req.url === '/stock.html') {
    indexPage(req, res, '/stock.html');
  }
  else if (req.url === '/contacts.json') {
    jsonSock(req, res, 'contacts.json')
  }
  else if (req.url === "/postContactEntry") {
    POST(req, res);
    res.writeHead(302, { 'Location': 'contacts.html' });
    return res.end("302 Temporary Redirect");
  }
  else{
    res.writeHead(404, {'Content-Type': 'text/html'});
    return res.end("404 Not Found");
  }
}).listen(port);

function indexPage(req, res, file) {
  fs.readFile('client' + file, function(err, html) {
    if(err) {
      throw err;
    }
    res.statusCode = 200;
    res.setHeader('Content-type', 'text/html');
    res.write(html);
    res.end();
  });
}

function jsonSock(req, res, file) {
  fs.readFile(file, function (err, json) {
    if (err) {
      throw err;
    }
    res.statusCode = 200;
    res.setHeader('Content-type', 'text/json');
    res.write(json);
    res.end();
  });
}

function POST(req, res) {
  var reqBody = '';
  // server starts receiving the form data
  req.on('data', function(data) {
    reqBody+= data;
  });// server has received all the form data
  req.on('end', function() {
    var jsonO = {}
    var postObj = qs.parse(reqBody);
    jsonO["name"] = postObj.name;
    jsonO["category"] = postObj.category;
    jsonO["location"] = postObj.location;
    jsonO["contact"] = postObj.contact;
    jsonO["email"] = postObj.email;
    jsonO["website_name"] = postObj.website_name;
    jsonO["website_url"] = postObj.website_url;
    fs.readFile('./contacts.json', 'utf8', function(err, data) {
      var file = JSON.parse(data);
      file.contacts.push(jsonO);
      var string = JSON.stringify(file);
      fs.writeFile('./contacts.json', string, function(err, data) {
        console.log(string);
      }); //Write clojure
    }); //Read clojure
  }); //req clojure
}