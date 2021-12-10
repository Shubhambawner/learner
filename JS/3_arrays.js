obj = { 1: 'a', 2: 'b', 3: 'c' };

arr = ['a', 1, 2, 3, 4, 5, "b", obj]

//setting and getting elements-----------
arr.length //8
arr[80] = 'yo'
arr[79] // is undefined!!

/**length one more than max. index */
arr["length"]  //81
arr.length //81


//modifications:-----------------------------------------------------------
brr = arr.slice(1, 5); //brr = [1, 2, 3, 4, 50] and arr = ["a", 1,2,3,4,50, "b",obj]
brr = arr.splice(1, 5); //brr = [1, 2, 3, 4, 50] and arr = ["a","b",obj]
brr.concat(arr);  //brr = [1, 2, 3, 4, 50,  "a","b",obj]

frr = arr.slice(); // copy of object arr is created, and asigned to frr

//array as stack/Queue:------------------------------------------------------------
h = arr.pop() // h = obj and arr = ["a","b"]
arr.push(obj) // arr = ["a","b",obj]
h = arr.shift() // h = "a" and arr = ["b",obj]
arr.unshift(h) // arr = ["a","b",obj]



//searching: 
arr.indexOf(obj) //2

//sorting
arr.sort() //dictionary order for words :arr = [1, 2, 3, 4, 50, 'a', 'b']
arr.reverse() // arr = ['b', 'a', 50, 4, 3, 2, 1]

//Array.prototype.map() method:
ar1 = [1, 2, 3, 4]
ar2 = Array.map(function(x){ return 2 * x; })
//ar2 = [2,4,6,8]
//when we create new array from existing, 



