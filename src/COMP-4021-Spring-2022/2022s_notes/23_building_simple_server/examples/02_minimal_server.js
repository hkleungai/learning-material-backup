const express = require("express");
const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use a web server to listen at port 8000
app.listen(8000);
