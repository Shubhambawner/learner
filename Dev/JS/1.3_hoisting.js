/***************
 * Hoisting is JavaScript's default behavior of moving declarations to the top  of the current scope 

   //* var: 
        a var can be used before it has been declared because it's declearation will be hoisted to the top.
   //! let & const : 
        can't be used before being used before being decleared
        //* reason: 
        Variables defined with let and const are hoisted to the top of the block, but not initialized.
        Meaning: The block of code is aware of the variable, but it cannot be used until it has been declared.
 */

if (1) {
    carName2 = "Volvo";
    const carName2;
    //error:  Uncaught SyntaxError: Missing initializer in const declaration
}
if (1) {
    carName3 = "Volvo";
    let carName3;
    //error:  Uncaught ReferenceError: Cannot access 'carName3' before initialization
}
if (1) {
    carName1 = "Volvo";
    var carName1;
    //carName1 = 'Volvo'
}    

