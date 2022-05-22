const express = require("express");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use the json middleware to get JSON data
app.use(express.json());

// Make some data
const users = {
    amy: { name: "Amy Cheung" },
    john: { name: "John Ho" },
    may: { name: "May Leung" },
    paul: { name: "Paul Chan" },
};

// Handle any POST requests for the path '/getuser'
app.post("/getuser", (req, res) => {
    // Get the username
    const { username } = req.body;

    // Return the user if found
    if (username && users[username])
        res.json(users[username]);
    else
        res.json("User not found");
});

// Use a web server to listen at port 8000
app.listen(8000);
