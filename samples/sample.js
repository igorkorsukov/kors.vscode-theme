const Module = require('module');

const GLOBAL_VAR = 42;

class MyClass {
    constructor() {
        this.a = 1;
        this.b = 2;
    }

    foo() {
        return this.a + this.b;
    }
}

function main() {
    console.log(GLOBAL_VAR);

    let localVar = "string";
    console.log(localVar);

    for (let i = 0; i < 10; i++) {
        console.log(i);
    }

    let obj = {
        a: 1,
        b: 2
    };

    Module.prop;
    Module.func();

    let myClass = new MyClass();
    console.log(myClass.foo());
}

main();