const express = require("express");
const app = express();
const fs = require("fs").promises;
const multer = require("multer");

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use the urlencoded middleware
app.use(express.urlencoded({ extended: true }));

// Use the multer middleware
const upload = multer({ dest: "uploads/" });

// Handle any POST requests for the path '/target'
app.post("/target", (req, res) => {
    const { firstname, lastname } = req.body;
    res.json({ firstname, lastname });
});

// Handle any POST requests for the path '/upload'
app.post("/upload", upload.single("myimage"), async (req, res) => {
    if (req.file) {
        await fs.copyFile(req.file.path, "public/" + req.file.originalname);
        await fs.unlink(req.file.path);

        res.send("<html><body>" + 
            "<img src='" + req.file.originalname + "'>" +
            "</body></html>");
    }
    else res.send("<html><body>File not found!</body></html>");
});

// Use a web server to listen at port 8000
app.listen(8000);

