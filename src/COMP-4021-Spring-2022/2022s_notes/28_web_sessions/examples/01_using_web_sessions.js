const express = require("express");
const session = require("express-session");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use the json middleware to get JSON data
app.use(express.json());

// Use the session middleware to maintain sessions
const mySession = session({
    secret: "secretkey",
    resave: false,
    saveUninitialized: false,
    rolling: true,
    cookie: { maxAge: 300000 }
});
app.use(mySession);

// Handle any GET requests for the path '/getname'
app.get("/getname", (req, res) => {
    if (req.session.name)
        res.json({ name: req.session.name });
    else
        res.json({ });
});

// Handle any POST requests for the path '/setname'
app.post("/setname", (req, res) => {
    const { name } = req.body;
    if (name)
        req.session.name = name;
    res.json({ name });
});

// Handle any GET requests for the path '/deletename'
app.get("/deletename", (req, res) => {
    const name = req.session.name;
    if (req.session.name)
        delete req.session.name;
    res.json({ name });
});

// Use a web server to listen at port 8000
app.listen(8000);
