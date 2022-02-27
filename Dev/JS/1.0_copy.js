//* for copying of arrays, json objects, symbolls, functions :::::


//! Not a copy: array is not coppied , just its reference is given
let arr = [1,2,3,4];
let brr = arr
brr[0] = 1000 // also, arr[0] = 0, as both arr and brr arerefering to same objects

//! shallow copy : immediate nested objects in the copy are not an actual copy, just their reference is given
//? https://developer.mozilla.org/en-US/docs/Glossary/Shallow_copy
//* ALL array methos like slice,splice,sort,map,filter... create shallow copy of the array
let arr1 = [1,2,3,[4,5,6]] 
let brr1 = [...arr1] //brr1 = [1,2,3,[4,5,6]]
brr1[0] = 1000 //but arr1[0] = 0, as both arr1[0] and brr1[0] not refering to the same objects
brr1[3][0] = 1000 //also, arr1[3][0] = 1000, as both arr1 and brr1 are refering to same objects

//! deep copy : all nested objects are re-created in a copy, changing one dosnt affect other objects
//! we can't create deep copy of non-serialisable objects, i.e those elements who are functions will be converted to null objects
//? https://developer.mozilla.org/en-US/docs/Glossary/Deep_copy
let arr2 = [1,2,3,[4,5,6]]
let brr2 = JSON.parse(JSON.stringify(arr2)) //brr2 = [1,2,3,[4,5,6]]

