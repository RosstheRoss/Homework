const express = require('express')
const db = require ('../dbio')
const router = express.Router()
router.use(express.urlencoded({ extended: true }))

router.get('/contacts', function (req, res) {
    // TODO: Implement code to fetch contacts from the database
    	table = db.getContacts();
	res.send("AAAAAAAAAAAA");
});


// TODO: Add implementation for other necessary end-points
router.post('/login', async function(req, res) {
	var loginInfo = req.body;
	var login = loginInfo.login;
	var pwd = loginInfo.password;
	let rows = [];
	
	// Query the database tbl_login with login and hashed password
	try {
		rows = await db.query(login, pwd); 
	}
	finally {
		// Provided there is no error, and the results set is assigned to a variable named rows:
		if (rows.length >= 1) {// the length should be 0 or 1, but this will work for now 
			//success, set the session, return success
			req.session.user = login;
			res.json({ status: 'success' });
			res.send("SUCC");
		} else
			res.send("FAIL");
		res.json({ status: 'fail' });
	}	
});

router.get('/logout', function(req, res) {
	if(!req.session.value) {
		res.send('Session not started, can not logout!');
	} else {
		console.log ("Successfully Destroyed Session!");
		req.session.destroy();
		res.send("Session Complete!");
		res.redirect('/login');
	}
});

module.exports = router;
