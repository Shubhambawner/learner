//* 1. spread operators for appending the array/object's contents 

//spread operator for arrays:
let arr = [1,2,3,4]
let brr = [...arr] //spread operator (spreads the all the content of array) brr = [1,2,3,4]
let crr = ['a','b',...brr,'c','d'] // crr = ['a','b',1,2,3,4,'c','d']


//spread operator for json objects
let obj = {1:'a',2:'b'}
let obj2 = {0:'z',...obj, 3: 'c'} //obj2 = {0:'z',1:'a',2:'b', 3: 'c'}

//* 2. rest operator with destructuring for making new variables

//rest operator in arrays (with array destructuring)
//note that here it has to be the last argument (to take all the "rest of the" parameters being passed)
let [a,b,...c] = [1,2,3,4,5,6] //c is array c = [3,4,5,6]

//rest operator in Json objects
//note that here it has to be the last argument (to take all the "rest of the" parameters being passed)
let {aj,bj,...cj} = {'ax':'a','bx':'b','3':'c','4':'d','5':'e','6':'f'} //cj is object:  cj = {1:'a',2:'b',3:'c',4:'d',5:'e',6:'f'}
//aj and bj are undefined here
let {ax,bx,...cj} = {'ax':'a','bx':'b','3':'c','4':'d','5':'e','6':'f'} //cj is object:  cj = {'3':'c','4':'d','5':'e','6':'f'} ax = 'a' ; bx = 'b'

//note that here it has to be the last argument (to take all the "rest of the" parameters being passed)
print = (a,b,...args) => {
    console.log(args) //this will be array of all the rest of the parameters passed
    console.log(...args) //this is spread operator to the args 
}
print(1,2,3,4) 
//3 4
//(2) [3, 4]