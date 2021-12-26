/**
 * objects in js are hash tables
 * name-value pairs
 * name is a string
 * value can be anything, other object array...
 * 
 * js objects need not be instances of a class, just create custome objects as key valye pairs
 * 
 */


// dog object with attributes and member function bark
// note that its not class, a custom object!!
dogBark = ()=>{
    console.log('bhu bhu')
}

dog = {
    legs : 4,
    eyes : 2,
    bark : dogBark,
    Name : 'shiro'
}

dog.bark() 
//thou the function has been attached to object, its still globally accecible!!!




