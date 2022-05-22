const stocks = require("./stocks");

stocks.getStock("AAPL")
    .then((stock) => {
        console.log(JSON.stringify(stock, null, "  "));
    })
    .catch((error) => {
        console.log(error.message);
    });
