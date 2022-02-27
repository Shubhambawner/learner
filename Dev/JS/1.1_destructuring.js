
//1. array destructuring:
let j = [1,2,3,4,5,6]
let [a,b] =  j //a = 1, b = 2

//2. object destructuring:
// only get the keys from object, 
//if those variables are not found as keys in json, they will be asignes undefined
//order dosent matter unlike in array destructuring
let obj = {'ax':'a','bx':'b','3':'c','4':'d','5':'e','6':'f'}
let {aj,ax,bx} = obj 
// ax = 'a' ; bx = 'b' ; aj = undefined

