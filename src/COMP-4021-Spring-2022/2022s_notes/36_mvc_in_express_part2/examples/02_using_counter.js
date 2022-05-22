const counter = require("./counter_node_module");

function useCounter() {
    const count = counter.get();
    console.log("Counter = " + count);

    if (count < 10) {
        counter.increase();
        setTimeout(useCounter, 1000);
    }
}
useCounter();
