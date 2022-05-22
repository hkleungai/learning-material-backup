(function(matrixstack) {
    "use strict";

    // Require TWGL
    var m4 = twgl.m4;

    /* The matrix stack */
    var stack = [m4.identity()];

    /*
     * Clear the matrix stack
     */
    matrixstack.clear = function() {
        stack = [m4.identity()];
    }

    /*
     * Load a matrix at the top of the stack
     */
    matrixstack.load = function(m) {
        stack[stack.length - 1] = m;
    }

    /*
     * Multiply a matrix to the top matrix of the stack
     */
    matrixstack.multiply = function(m) {
        stack[stack.length - 1] = m4.multiply(stack[stack.length - 1], m);
    }

    /*
     * Duplicate the top matrix in the stack and
     * increase the size of the stack by one
     */
    matrixstack.push = function() {
        stack.push(stack[stack.length - 1]);
    }

    /*
     * Pop the top matrix from the stack
     */
    matrixstack.pop = function() {
        if (stack.length > 1)
            stack.pop();
        else
            matrixstack.clear();
    }

    /*
     * Get the top matrix of the stack
     */
    matrixstack.top = function() {
        return stack[stack.length - 1];
    }
 
}(window.matrixstack = window.matrixstack || {}));
