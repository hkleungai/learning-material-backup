const yahooFinance = require('yahoo-finance2').default;

async function getStock(code) {
    const summary = await yahooFinance.quoteSummary(code);
    const prices = await yahooFinance.historical(code,
        { period1: "2001-01-01" });

    return { summary, prices };
}

module.exports = { getStock };
