const express = require("express");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Handle any GET requests for the path '/serverinfo'
app.get("/serverinfo", (req, res) => {
    res.json({ name: "First Node.js Server" });
});

// Use a web server to listen at port 8000
app.listen(8000);
