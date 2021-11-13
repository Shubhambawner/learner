//console 
console.log('hello')
console.warn('hello')
console.error('hello')
alert('hello')

// Variables and data types -----------------------------------------------------

// numbers:
var myNumber = 5;
var myNumber = 5.5;
var myNumber = 5.5e3;
var myNumber = 5.5e-3;
var myNumber = Infinity;
var myNumber = 1 / 0;//NaN

// boolean
var myBoolean = true;
var myBoolean = false; //any nonzero number is bool true, 0 is false

// null and undefined and NaN----------------------------------------------------
var j = null;
var t;
console.log(j, t);//null undefined
/**
 * null is like a NULL pointer of c++, which is explicitly defined null
 * undefined is, vhen any identifier is not asigned any value
 * 
 */
 
// arithmatic and logical operators-------------------------------------------------
a = 'a'; b = 'b';
j = typeof b; //j = 'string'
k = typeof a; //k = 'string'
console.log(a === b);  //true if typeof a == typeof b and a==b
/**
 * in js == operator wont check type, 6 == '6' is true, so use === 
 * 5==5 true         5===5 true
 * 5==4 false        5===4 false
 * 5=='5' true       5==='5' false
 * 
 */
//ternary operator _?_:_
var allowed = (age > 18) ? 'yes' : 'no';


//NaN is when operator undefined for that type is used, like:
a =  'string' * 2 //NaN


/*
all same to java/c++
*/

//if else while-------------------------------------------------------------------
if (1) {
    console.log('yes')
} else if (!0) {
    console.log('yes!!')
} else {
    while (true) {
        console.log('no!!')
    }
}

// access modifiers for identifiers :-----------------------------------------------------
if (1) {
    var x = 10; //  global
    let y = 10; // scoped to the block
    const z = 10;
    w = 34; // by default it is decleared as global

    // let y = 10; // error:  variable y is already defined!
}
console.log(y, x, w); //only y not reachable!!

/* here x is an identifier
 * is unique to every variable we create(no multiple objects of same name)
 * cant start with number, or any symbol exept _ and $ 
 * cant be any reserved keyword.
 * JS is loosely typed language, means, type of variable is not pre defined (int , string,...)
 */


//switch case 
let key_var = 1;
switch (key_var) {
    case 1:
        console.log('one');
        break;

    default:
        console.log('two');
        break;
}

//for..in
arr = [1,2,3,4,5]
for (const i in arr) {
    console.log(i)
}

//for..of
for (const i of jso) {
    
}










