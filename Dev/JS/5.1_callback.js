/**
 * CALLBACK FUNCTION:
 * the function that takes other functuion as an input, and runs that while its own execution is called 
 * a call back function
 * ex: setInterval
 */

function getData(to_callback_Function){
    /**code to get data from server */
    to_callback_Function(); 
    /**after fetching is compleated, this will be called */
   }
   
   function updateUI(){/**updates ui according to the data fetched by server */}
   
   //using above two functions:
   let el = document.querySelector("div")
   el.onclick = getData(updateUI());

   
   
//* Call-Back functions are by default Syncronous, 
//* they are executed in the order they are written, and they
//* mani function will only return when all callbacks are complete
function sayHelloSync (name,callback){
    callback('hello '+name)
}

console.log('before')

//sayHelloSync (name, callbackFunction)
sayHelloSync('BrainBell',(result) => {
console.log(result)
})

console.log('after')

/**
before
hello BrainBell
after
 */
