const express = require("express");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use the EJS template engine
app.set("view engine", "ejs")

// Handle any GET requests for the path '/'
app.get("/", (req, res) => {
    res.redirect("http://money.com");
});

// Handle any GET requests for the path '/welcomemessage'
app.get("/welcomemessage", (req, res) => {
    const welcomeMessage = "Hi!";

    res.send(`<html><body>${welcomeMessage}</body></html>`);
});

// Handle any GET requests for the path '/welcome'
app.get("/welcome", (req, res) => {
    res.render("welcome");
});

// Handle any GET requests for the path '/sayhi'
app.get("/sayhi", (req, res) => {
    res.render("sayhi", { name: "Paul" });
});

// Use a web server to listen at port 8000
app.listen(8000);
