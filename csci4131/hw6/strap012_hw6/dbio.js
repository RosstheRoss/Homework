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
	let ret = '';
	connection.query('SELECT * FROM tbl_accounts', function(err,rows,fields) {
		
		if (err) throw err;
		if (rows.length == 0) {
			console.log("There are no entries in the accounts field!");
		} else {
			for (var i = 0 ; i < rows.length; i++) {
				if (rows[i].acc_login.localeCompare(user) === 0) {
					if (bcrypt.compareSync(pass, rows[i].acc_password)) {
    							ret += rows[i];
					}
				}
			}
		}
	});
	return ret;
}

function getContacts() {
	let conTab = []
	connection.query('SELECT * FROM tbl_contacts', function(err,rows,fields) {
		for (let i=0; i<rows.length; i++) {
			conTab[i] = rows[i];
		}
	});
	return conTab;
}

// Parameterized Insert
var rowToBeInserted = {
    Title: 'A Book', // Dummy Book Name
    Category: 'General', // Dummy Category Type
    ISBN : '0000001234'// Dummy 
  };

//connection.query('INSERT books SET ?', rowToBeInserted, function(err, result) {  //Parameterized insert
//    if(err) throw err;
//    console.log("Values inserted");
//  });
  
var Title = 'Another Book';
var Cat = 'Fiction';
var ISBN = '0000002345';
  
//var sql = 'INSERT INTO books (Title,Category,ISBN) VALUES (' + '"' + Title + '"' + ',' + '"' + Cat + '"' + ',' + '"' + ISBN + '"' + ')';
//connection.query(sql,function(err,result) {
//	  if (err) throw err;
//	  console.log ("Version 2 values inserted");
//	});


