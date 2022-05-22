const express = require("express");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Handle any GET requests for the path '/target'
app.get("/target", (req, res) => {
    const { firstname, lastname } = req.query;
    res.json({ firstname, lastname });
});

// Use a web server to listen at port 8000
app.listen(8000);

