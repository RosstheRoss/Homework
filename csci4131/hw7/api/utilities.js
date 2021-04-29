const express = require('express')
const db = require ('../dbio')
const router = express.Router()
router.use(express.urlencoded({ extended: true }))

router.get('/contacts', function (req, res) {
    db.getContacts().then(function(table) {
		res.send(table)
	});
});

router.post('/login', async function(req, res) {
	var loginInfo = req.body;
	var login = loginInfo.login;
	var pwd = loginInfo.password;
	let rows = [];
	
	// Query the database tbl_login with login and hashed password
	db.query(login, pwd).then(function(rows) {
		// Provided there is no error, and the results set is assigned to a variable named rows:
		if (rows.length >= 1) {// the length should be 0 or 1, but this will work for now 
			//success, set the session, return success
			req.session.user = login;
			res.json({ status: 'success' });
		} else {
			res.json({ status: 'fail' });
		}
	}); 
		
});

router.get('/logout', function(req, res) {
	if(!req.session.user) {
		res.send('Session not started, can not logout!');
	} else {
		req.session.destroy();
		res.redirect('/login');
	}
});

router.post('/addContact', function(req, res) {
	var contact = req.body;
	db.addContact(contact).then(function() {
		res.redirect('/contacts');
	});
});

module.exports = router;
