const express = require("express");
const cookieParser = require("cookie-parser");
const app = express();

// Use cookie parser to enable cookies
app.use(cookieParser());

// Handle any GET requests for the path '/setcookie'
app.get("/setcookie", (req, res) => {
    // Create a cookie
    res.cookie("username", "pchan");

    // Return the currently available cookies
    res.json(req.cookies);
});

// Handle any GET requests for the path '/viewcookie'
app.get("/viewcookie", (req, res) => {
    // Return the currently available cookies
    res.json(req.cookies);
});

// Handle any GET requests for the path '/clearcookie'
app.get("/clearcookie", (req, res) => {
    // Remove the cookie
    res.clearCookie("username");

    // Return the currently available cookies
    res.json(req.cookies);
});

// Use a web server to listen at port 8000
app.listen(8000);
