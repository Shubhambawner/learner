obj = { 1: 'a', 2: 'b', 3: 'c' };

arr = ['a', 1,2,3,4,5, "b", obj]




//modifications:-----------------------------------------------------------
arr[5] = 50
brr = arr.slice(1,5); //brr = [1, 2, 3, 4, 50] and arr = ["a", 1,2,3,4,50, "b",obj]
brr = arr.splice(1,5); //brr = [1, 2, 3, 4, 50] and arr = ["a","b",obj]
brr.concat(arr);  //brr = [1, 2, 3, 4, 50,  "a","b",obj]

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




