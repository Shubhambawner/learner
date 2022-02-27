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
//! ALL these modifications create SHALLOW COPY of array objectss, Caution !

let numbers = [2, 3, 5, 7, 11, 13, 17];
// create another array by slicing numbers from index 3 to 5
let newArray = numbers.slice(3, 6); // [5, 7, 11]


brr = arr.splice(1, 5); //brr = [1, 2, 3, 4, 50] and arr = ["a","b",obj]
brr = arr.splice(1, 5, o1,o2,...arr3); 
// 1 is index, 5 is number of elements to remove and return, o1,o2,...arr3 are the objects to be added after index 1

brr.concat(arr);  //brr = [1, 2, 3, 4, 50,  "a","b",obj]


//array as stack/Queue:------------------------------------------------------------
h = arr.pop() // h = obj and arr = ["a","b"]
arr.push(obj) // arr = ["a","b",obj]
h = arr.shift() // h = "a" and arr = ["b",obj]
arr.unshift(h) // arr = ["a","b",obj]



//searching: ----------------------------------------------------------------------------------
arr.indexOf(obj) //2

//sorting----------------------------------------------------------------------------------
//! ALL these create SHALLOW COPY of array objectss, Caution 
//* In Place methods, edit actual array also !
arr.sort() //dictionary order for words :arr = [1, 2, 3, 4, 50, 'a', 'b']
arr.reverse() // arr = ['b', 'a', 50, 4, 3, 2, 1]

//Array.map() method:----------------------------------------------------------------------------------
//! SHALLOW COPY of array objectss, Caution
ar1 = [1, 2, 3, 4]
ar2 = ar1.map(function(x){ return 2 * x; })
//ar2 = [2,4,6,8]


/**
let arr1 = [1,2,3,[4,5,6]] 
undefined
h = arr1.pop()
(3) [4, 5, 6]
y = arr1.shift()
1
arr2 = arr1.push(2)
3
arr2
3
let arr1 = [1,2,3,[4,5,6]] 
undefined
arrw = arr1.concat(arr1)
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]
arrw[2][0] = 1000
1000
arrw
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]0: 11: 22: 33: (3) [4, 5, 6]4: 15: 26: 37: (3) [4, 5, 6]length: 8[[Prototype]]: Array(0)
arrw[3][0] = 1000
1000
arrw
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]0: 11: 22: 33: (3) [1000, 5, 6]4: 15: 26: 37: (3) [1000, 5, 6]length: 8[[Prototype]]: Array(0)
arrh = arrw.slice()
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]
arrh[3][0] = 5
5
arrh
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]0: 11: 22: 33: (3) [5, 5, 6]4: 15: 26: 37: (3) [5, 5, 6]length: 8[[Prototype]]: Array(0)
arrw
(8) [1, 2, 3, Array(3), 1, 2, 3, Array(3)]0: 11: 22: 33: (3) [5, 5, 6]4: 15: 26: 37: (3) [5, 5, 6]length: 8[[Prototype]]: Array(0)
arrr = arrw.reverse()
(8) [Array(3), 3, 2, 1, Array(3), 3, 2, 1]
arrr[0][0] = 20
20
arrw

 */



