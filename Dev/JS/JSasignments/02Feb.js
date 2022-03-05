// https://docs.google.com/document/d/1_o37625XMYDlTaayMS2xrB2S1SObec7AwMyA3jqCvWI/edit#

/**
 * 
   //! string operations: 
 * //* str.charCodeAt(index) 
 * //* String.fromCharCode(65) //A
 * 
 */

// 1. Program to Swap Two Variables using a temporary variable
let swap = (a,b)=>{
    let temp = a;
    a = b;
    b = temp;
    console.log(a,b);
}

// 2. Program to Swap Two Variables using destructuring assignment
let swap2 = (a,b)=>{
    [a,b] = [b,a];
    console.log(a,b);
}

// 3. Check if a number is even using if-else
let isEven = (num)=>{
    if(num%2==0)
        return true;
    else
        return false;
}

// 4. Check if a number is even using ternary operator
let isEven2 = (num)=>{
    return (num%2==0)?true:false;
}

// 5. "Consider an array of size 10 having a mixture of even and odd numbers.
// 5.a) Filter only odd numbers without using array functions.
let odd = (arr)=>{
    let oddArr = [];
    for(let i=0;i<arr.length;i++){
        if(arr[i]%2!=0)
            oddArr.push(arr[i]);
    }
    return oddArr;
}

// 5.b) Filter only even numbers using array functions.
let even = (arr)=>{
    return arr.filter(num=>num%2==0);
}

//? why is the size given, it could be done without that too!

// 6 Consider an array of size 10 with different numbers.
//      6.a) Get the maximum value among them using Math
let max = (arr)=>{
    return Math.max(...arr);
}

// 6 Consider an array of size 10 with different numbers.
//      6.b) Get the maximum value among them without using Math
let max2 = (arr)=>{
    let max = arr[0];
    for(let i=1;i<arr.length;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

// 7. Write a function to add two numbers. Also, supply it with default parameter values
let add = (a=0,b=0)=>{
    return a+b;
}

// 8. Write a function to add n numbers. The value of n is not known. Use rest operator
let addN = (...nums)=>{
    let sum = 0;
    for(let i=0;i<nums.length;i++){
        sum += nums[i];
    }
    return sum;
}

// 9. Write a program for concatenating two arrays using a spread operator.
let concat = (arr1,arr2)=>{
    return [...arr1,...arr2];
}

// 10. Removing duplicate characters for a given string

let refineString = (str)=>{
    let charData = [] // we will use this array as a hash table, with key being index , each index corrosponds to the char with absolute value equal to that index
    let ans = ""
    for (let index = 0; index < str.length; index++) {
        if(!charData[str.charCodeAt(index)]){
            ans+=str[index]
            charData[str.charCodeAt(index)] = true //26 bytes
        }
    }
    console.log(ans);
    return ans
}

let refineStringBit = (str)=>{
    let charData = 0 // we will use this array as a hash table, with key being index , each index corrosponds to the char with absolute value equal to that index
    let ans = ""
    for (let index = 0; index < str.length; index++) {
        if(!charData[str.charCodeAt(index)]){
            ans+=str[index]
            charData[str.charCodeAt(index)] = true //26 bytes
        }
    }
    console.log(ans);
    return ans
}


let parseString = (str)=> [...new Set(str)].join('') //most probably set uses hash tables internally

let removeDuplicates = (str)=>{
    let charData = {}
    let ans = ""
    for (let index = 0; index < str.length; index++) {
        if(!charData[str[index]]){ //! this step actually takes log(n) time , so actual complexicity is not n*log(n)
            charData[str[index]] = str[index]
            ans+=str[index]
        }
    }
    console.log(ans);
    return ans;
}

refineString("as234235dasd45621asda573132535sdasd!@#$%^!@#$%^#%@#%~~``  ##W   EWTEtdrerDR")
//as2345d617!@#$%^~` WETtreDR

