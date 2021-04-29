var mysql = require("mysql");
var bcrypt = require("bcrypt");

var connection = mysql.createConnection({
  host: "cse-mysql-classes-01.cse.umn.edu",
    user: "C4131S21U83",              
    password: "6919",                  
    database: "C4131S21U83",           
    port: 3306
});

connection.connect(function(err) {
  if (err) {
    throw err;
  };
  console.log("Connected to MYSQL database!");
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
