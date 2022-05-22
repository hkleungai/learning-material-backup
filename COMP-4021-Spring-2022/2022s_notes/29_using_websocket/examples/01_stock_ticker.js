const express = require("express");
const app = express();
const { createServer } = require("http");
const { Server } = require("socket.io");
const httpServer = createServer(app);
const io = new Server(httpServer);

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Prepare the WebSocket
io.on("connection", (socket) => {
    // Store the playing status
    let playing = false;

    // Store the timeout
    let timeout;

    // Continuously send data to the browser
    const ticker = function() {
        if (playing && socket.connected) {
            // Set a random price
            let price = 100 + Math.random() * 10 - 5;
            let change = price - 100;

            // Send it to the browser
            const data = { price, change };
            socket.emit("update", JSON.stringify(data));

            // Do it again
            timeout = setTimeout(ticker, 1000);
        }
    };

    // Listen for the play/pause command
    socket.on("command", (command) => {
        if (command == "play") {
            playing = true;
            clearTimeout(timeout);
            ticker();
        }
        else
            playing = false;
    });
});

// Use a web server to listen at port 8000
httpServer.listen(8000);
