//? https://medium.com/@ashfaqueahsan61/time-complexities-of-common-array-operations-in-javascript-c11a6a65a168


//! array direct access: O(1) 
console.log(arr[4]) 

//! array element searching: O(n)
arr.indexOf(50) 

//! array insertion and deletion in end: O(1)
arr.push(50)
arr.pop() 

//! array insertion and deletion in beginning: O(n)
arr.unshift(50)
arr.shift() // shallow copy

//! array modification(reverse, splice, slice, concat) : O(n)
arr.reverse() // ? in place    
arr.splice(a,b) //
arr.slice(a,b) //
arr.concat(arr2) // 
arr.concat('G') //
//In the case above, the arr array gets copied with an additional element with value ‘G’. So the Big O for this would be O(n).

//! iteration : O(n)
arr2 = arr.map(x => 2 * x) //
arr.forEach(x =>console.log(x))
arr.filter(x => x > 2) //
arr.every(x => x > 2)
arr.reduce((a,b) => a+b)

//! Sorting : O(n log n)
arr.sort() //? in place  