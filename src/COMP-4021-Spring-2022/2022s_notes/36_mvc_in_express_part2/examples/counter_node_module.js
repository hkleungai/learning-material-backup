let count = 0;

const increase = function() {
    count = count + 1;
};

const get = function() {
    return count;
};

module.exports =  { increase, get };
