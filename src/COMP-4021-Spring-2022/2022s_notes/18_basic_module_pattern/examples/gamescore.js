// This defines the GameScore module
const GameScore = function(initScore) {

    // The current score
    let score = initScore;

    // The element holding the score
    const element = $("#score");

    // The update display function
    const updateDisplay = function() {
        element.text(score);
    };

    // The increase score function
    const increase = function() {
        score = score + 10;
        updateDisplay();
    };

    // The decrease score function
    const decrease = function() {
        score = score - 10;
        if (score < 0)
            score = 0;
        updateDisplay();
    };

    // Return (expose) the required functions
    return {
        increase: increase,
        decrease: decrease
    };
};
