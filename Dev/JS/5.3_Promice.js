// promice

let done = true;

let areUfree = new Promise((resolve, reject)=>{
    if(done) resolve("Yes, I am free")
    else reject("No, I am busy")
})

// areUfree.then((result) => {
//     console.log(result)
// }).catch((err) => {
//     console.log(err)
// });

 let fs = require('fs')
let getFile = new Promise((resolve,reject)=>{
    fs.readFile('d:\\lerner\\Dev\\JS\\5.3_Promice.js',(err,data)=>{
        if(data){console.log(data); resolve(data)}
        else reject(err)
    })
})

getFile
// console.log(typeof getFile)
// .then(ok=>{
//     console.log(ok)
// }).catch(err=>{
//     console.log(err)
// })

// let file = fs.readFile('d:\\lerner\\Dev\\JS\\5.3_Promice.js',(err,data)=>{
//         if(data) return (data)
//         else return (err)
//     }) 
// console.log(file) //undefined

/** //* error message for no file found: 
 * [Error: ENOENT: no such file or directory, open ''] {
  errno: -4058,
  code: 'ENOENT',
  syscall: 'open',
  path: ''
}
 */
/** //* output for raw buffer, we need to cook it first to be eaten ;)
 * <Buffer 2f 2f 20 70 72 6f 6d 69 63 65 0d 0a 0d 0a 2f 2f 20 6c 65 74 20 64 6f 6e 65 20 3d 20 74 72 75 65 3b 0d 0a 0d 0a 2f 2f 20 6c 65 74 20 61 72 65 55 66 72 ... 722 more bytes>
 */
