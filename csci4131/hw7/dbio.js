var mysql = require("mysql");
var bcrypt = require("bcrypt");
var fs = require("fs");
var xml2js = require("xml2js");
var parser = new xml2js.Parser();
var conInfo;
var connection;

fs.readFile(__dirname + '/dbconfig.xml', function (err, data) {
	if (err) throw err; 
	parser.parseString(data, function (err, result) { 
		if (err) throw err; 
		conInfo = result; 
	});
	connection = mysql.createConnection({
		host: conInfo.dbconfig.host[0],
		user: conInfo.dbconfig.user[0],
		password: conInfo.dbconfig.password[0],
		database: conInfo.dbconfig.database[0],
		port: conInfo.dbconfig.port[0]
	});

	connection.connect(function (err) {
		if (err) {
			throw err;
		};
		console.log("Connected to MYSQL database!");
	});
});



function passcheck(user,pass) {
	return new Promise(function(resolve, reject) {
		connection.query('SELECT * FROM tbl_accounts', function(err, rows, fields) {
			let ret = [];
			if (err) {
				return reject(err);
			}
			for (var i = 0; i < rows.length; i++) {
				if (rows[i].acc_login.localeCompare(user) === 0) {
					if (bcrypt.compareSync(pass, rows[i].acc_password)) {
						ret += rows[i];
					}
				}
			}
			resolve(ret);
		});
	});
}

function getContacts() {
	return new Promise (function(resolve, reject) {
		let conTab = []
		connection.query('SELECT * FROM tbl_contacts', function (err, rows, fields) {
			if (err) {
				return reject(err);
			}
			resolve(rows);
		});
	});
}

function addContacts(contact) {
	let newCon = {
		name: contact.name,
		category: contact.category,
		location: contact.location,
		contact_info: contact.contact,
		email: contact.email,
		website_url: contact.website_name,
	}
	return new Promise(function(resolve, reject) {
		connection.query('INSERT tbl_contacts SET ?', newCon, function (err, result) {  //Parameterized insert
			if (err) throw err;
			console.log("Values inserted");
			resolve();
		});
	});
	
}



  
exports.addContact = addContacts;
exports.query = passcheck;
exports.getContacts = getContacts;
