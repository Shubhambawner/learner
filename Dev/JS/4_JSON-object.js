obj = {1:'a', 2:'b', 3:'c'};
cbj = {1:'a', 2:'b', 'c':obj};
ybj = {1:'a', 2:'b', 'c':cbj};

//accessing and modifying json object elements:-------------------------------

ybj['c'] // {1:'a', 2:'b', 'c':{1:'a', 2:'b', 3:'c'}}
ybj['c']['c'] // {1:'a', 2:'b', 3:'c'}
ybj['c']['c'][3] // 'c'
ybj['c']['c'][3] = "z";




//modify the json object: -----------------------------------------------------

//1. unspread syntax: : to append new key-value pairs to the object:
obj = {1:'a', 2:'b', 3:'c'};
obj = {0:'D', ...obj , 4:'d', 5:'e'};
//now obj = {0:'D', 1: 'a', 2: 'b', 3: 'c', 4: 'd', 5:'e'}

//2. delete keyword : to delete a key-value pair from the object:
obj = {1:'a', 2:'b', 3:'c'};
delete obj[2];
//now obj = {1: 'a', 3: 'c'}



//JSON and string conversions----------------------------------------------------

Sybj = JSON.stringify(ybj); // '{"1":"a","2":"b","c":{"1":"a","2":"b","c":{"1":"a","2":"b","3":"c"}}}'
//now store it in some array, put into local storage...

//after retriving string version of JSON object, parse it back to JSON object RECURSIVELY:
ybj = JSON.parse(Sybj);
//now ybj = {"1":"a","2":"b","c":{"1":"a","2":"b","c":{"1":"a","2":"b","3":"c"}}}

/*thumb rule: 
 * whenever we store json anywhere(some array or other json), convert to string first
 * then parse it back to the object whenever we retrive and use json object.
*/


