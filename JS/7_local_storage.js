arr = [77, 2, 3, 4, 5, 'a', 'b', {1:"r"}]
obj = {1:'a', 2:'b', 3:'c'};



//this is why JSON-string conversion becomes necessary : as localstorage only stores strings:
localStorage.setItem(5,obj)
localStorage.getItem(5)
'[object Object]'

//also arrays get converted to strings, which are hard to re-store later
localStorage.setItem(2,arr)
localStorage.getItem(2)
'77,2,3,4,5,a,b,[object Object]'

/**
 * 
 * complex arrays: [1,2,3,[4,5,6,[7,8,9]]] becoms: '1,2,3,4,5,6,7,8,9'
 * josn object becoms: [object Object]
 * only string forms are stored in localstorage
 * 
 */


