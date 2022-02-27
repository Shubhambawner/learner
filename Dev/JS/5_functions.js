//simple functions
function hello(name) {
    console.log("Hello ", name);
}

//arguments---------------------------------------------------
//1. arguments array
function avr() {
    var a = 0;
    for (const i of arguments) {
        a += i;
    }
    return a / arguments.length
}
/**
 * all arguments passed to function are stored in array 'arguments'
 * any argument passed can be accessed under function via arguments array
 * in js we need not to specify the number and type of arguments while creating a function
 * 
 */

//2. rest operator(rest parameters operator)
function profit(cost, ...sellingPrise) {
    var a = 0;
    for (const i of sellingPrise) {
        a += i;
    }
    return a
}
/**
 * all values after cost argument get stored in array named sellingPrise
 */

//function as object creator
function person(name, surname) {
    this.firstname = name;
    this.lastname = surname;
}
/**
 * in js whenever a function is called, 
 * function is created as a new object with given input parameters,
 * as an instance of its defination
 * just like a constructor of some object,
 *   
 */

foo = new person('foo', 'bar')
//now foo is an object of type person
/**
 * here,@param  new operator asigns object created to foo, as function person is bydfault void return type
 * @param this keyword is important, 
 * it connects parameters to object being created
 * without "this" keyword
 * parameters defined inside function block wont be attached or accecible through object beibg created via new
 * 
 */

person.prototype.fullName = function () {
    return this.firstname + this.lastname
}

/**
 * @param prototype:
 * every function object has a common parameters and functions, defined under an object named prototype
 * this is like class body of that object.
 * 
 * here person.prototype has become object: {fullName: ƒ, constructor: ƒ}
 */

//anonymus functions---------------------------------------------------------------------------
fc = function (a, b, c) { a += b; b += c; return a } // anonymus function
fc = (a, b, c) => { a += b; b += c; return a } // arrow functions

/**
 * arrow functions are useless, 
 * dont have this, neew keywords support
 * use anonymus functions mostly!
 */

//returning a function!!!
function greet(token) {
    return function (name) {
        console.log(token , name)
    }
}

// this is how the function got customised!!!
greetHello = greet('hello')
greetBye = greet('bye')
greetHello('sam') //hello sam
greetBye('sam') //Bye sam

