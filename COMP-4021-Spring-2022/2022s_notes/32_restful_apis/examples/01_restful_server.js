const express = require("express");
const fs = require("fs");

const app = express();

// Use the 'public' folder to serve static files
app.use(express.static("public"));

// Use the json middleware to get JSON data
app.use(express.json());

// Handle the GET request for the book resources
app.get("/books", (req, res) => {
    // Read the books database 
    const books = JSON.parse(fs.readFileSync("books.json"));
    
    // Return all books
    res.json(books);
});

// Handle the GET request for individual book resources
app.get("/books/:bookId", (req, res) => {
    // Get the book id
    const bookId = req.params.bookId;

    // Read the books database 
    const books = JSON.parse(fs.readFileSync("books.json"));

    // Find and return the book
    for (const book of books) {
        if (book.id == bookId) {
            // Return the book
            res.json(book);
            return;
        }
    }
    
    // Book not found
    res.sendStatus(404);
});

// Handle the POST request for creating new book
app.post("/books", (req, res) => {
    // Get the new book
    const newBook = req.body;

    // Read the books database 
    const books = JSON.parse(fs.readFileSync("books.json"));

    // Find the maximum id
    let id = 0;
    for (const book of books) {
        if (id < book.id) id = book.id;
    }
    id = id + 1;

    // Save the new book
    newBook.id = id;
    books.push(newBook);
    fs.writeFileSync("books.json", JSON.stringify(books, null, "  "));
    
    // Return success
    res.sendStatus(201);
});

// Handle the PUT request for updating a book
app.put("/books/:bookId", (req, res) => {
    // Get the book id
    const bookId = req.params.bookId;

    // Get the book
    const updatedBook = req.body;

    // Read the books database 
    const books = JSON.parse(fs.readFileSync("books.json"));

    // Find and update the book
    for (let i = 0; i < books.length; i++) {
        if (books[i].id == bookId) {
            // Update the book
            updatedBook.id = bookId;
            books[i] = updatedBook;
            fs.writeFileSync("books.json", JSON.stringify(books, null, "  "));

            // Return success
            res.sendStatus(200);
            return;
        }
    }
    
    // Book not found
    res.sendStatus(404);
});

// Handle the DELETE request for deleting a book
app.delete("/books/:bookId", (req, res) => {
    // Get the book id
    const bookId = req.params.bookId;

    // Read the books database 
    const books = JSON.parse(fs.readFileSync("books.json"));

    // Find and delete the book
    for (let i = 0; i < books.length; i++) {
        if (books[i].id == bookId) {
            // Delete the book
            books.splice(i, 1);
            fs.writeFileSync("books.json", JSON.stringify(books, null, "  "));

            // Return success
            res.sendStatus(200);
            return;
        }
    }
    
    // Book not found
    res.sendStatus(404);
});

// Use a web server to listen at port 8000
app.listen(8000);
