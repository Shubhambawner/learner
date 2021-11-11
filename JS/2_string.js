// strings::
//1. decleration
s1 = "Hello World!";
s2 = 'Hello World!';
s3 = `Hello World!`; //baktick, can imbed the characters!

//1. access contents:
console.log(s1[0]);//'H'

//2. length:
console.log(s1.length);//12

//3. concatenation:
s4 = s1 + s2;//Hello World!Hello World!
s1 =+ s2;//Hello World!Hello World!

//4. string modification methods:----------------------------------------------------
//1. substring() & slice():
s1.substring(0,9)// 0 to 9, NOT including 9
'Hello Wor'
s1.slice(0,9)
'Hello Wor'

s1.substring(9,0)
'Hello Wor'
s1.slice(9,0)
''
//note difference, slice() will return empty string if start > end.

//2. replace():
s1.replace('Hello', 'Goodbye'); //'Goodbye World!'

//3. reverse():
s1.reverse(); //'!dlroW olleH'

//4.1 toUpperCase():
s5 = s1.toUpperCase();//HELLO WORLD!

//4.2. toLowerCase():
s6 = s1.toLowerCase();//hello world!



//SEARCHING OPERATIONS --------------------------------------------------------------------     
//1. char at i:
s7 = s1[0];//'H'
//2. indexOf() and lastIndexOf():
s8 = s1.indexOf('or'); 
// returns the index of the first occurence of the search string
// if not found, returns -1

//Number string methods:----------------------------------------------------
//1. valueOf():
u = valueOf('34') // 34 i.e converts the string to a number
//2. toString():
u.toString(); //'34' i.e converts the number to a string

//array - string opreations:------------------------------------------------------
arr= [1,2,3,4,5];
s1 = arr.toString(); //'1,2,3,4,5'

arr = s1.split(','); //arr = ['1', '2', '3', '4', '5']


