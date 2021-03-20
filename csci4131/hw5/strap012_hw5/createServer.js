
const http = require('http');
const url = require('url');
const fs = require('fs');
const qs = require('querystring');

const port = 9001;
http.createServer(function (req, res) {
  var q = url.parse(req.url, true);
  var filename = "." + q.pathname;
  if(req.url === '/'){
    res.writeHead(302, { 'Location': 'contacts.html' });
    return res.end("302 Temporary Redirect");
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

