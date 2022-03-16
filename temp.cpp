#include <bits/stdc++.h>
using namespace std;
// string minRemoveToMakeValid(string s)
// {
//     int a = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(')
//         {
//             a++;
//             ////cout <<s[i]<<" "<< i << "q\n";
//         }
//         if (s[i] == ')')
//         {
//             if (a == 0)
//             {
//                 s[i] = '_';
//                 ////cout <<s[i]<<" "<< i << "w\n";
//             }
//             else
//             {
//                 a--;
//                 ////cout <<s[i]<<" "<< i << "e\n";
//             }
//         };
//     }
//     for (int i = s.size()-1; i >=0  && a > 0; i--)
//     {
//         if (s[i] == '(')
//         {
//             s[i] = '_';
//             a--;
//         }
//     }
//     string ans = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] != '_')
//         {
//             ans += s[i];
//         }
//     }
//     return ans;
// }



// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a = 50, b = 10, temp;
//     //cout << "Before swapping." << endl;
//     //cout << "a = " << a << ", b = " << b << endl;
//     temp = a;
//     a = b;
//     b = temp;
//     //cout << "\nAfter swapping." << endl;
//     //cout << "a = " << a << ", b = " << b << endl;
//     return 0;
// }
/*
Before swapping.
a = 50, b = 10
After swapping.
a = 10, b = 50
*/
// #include <bits/stdc++.h>
// using namespace std;

// /* function to calculate average of
//  * N numbers.
//  */
// double average(double n1[], int size)
// {
//     double sum = 0; // to store sum value
//     // calculate sum value
//     for (int i = 0; i < size; ++i)
//     {
//         sum += n1[i];
//     }
//     // calculate average value
//     // and return to caller function
//     return sum / size;
// }

// // main function
// int main()
// {
//     int size;   // to store size
//     double avg; // to store result value

//     // take size as input values
//     //cout << "Enter number of numbers: ";
//     cin >> size;

//     // declare array
//     double arr[size]; // to store numbers

//     // take array input
//     //cout << "Enter "<<size<<" space separated elements: ";
//     for (int i = 0; i < size; ++i)
//     {
//         cin >> arr[i];
//     }

//     // function to find avg of N numbers
//     avg = average(arr, size);

//     // display result
//     //cout << "Average = " << avg << endl;

//     return 0;
// }
/*
Enter number of numbers: 3
Enter 3 space separated elements: 15.5 20.5 25.9
Average = 20.6333
*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int num, originalNum, remainder, result = 0;
//     //cout << "Enter a three-digit integer: ";
//     cin >> num;
//     originalNum = num;
//     while (originalNum != 0)
//     {
//         // remainder contains the last digit
//         remainder = originalNum % 10;
//         result += remainder * remainder * remainder;
//         // removing last digit from the orignal number
//         originalNum /= 10;
//     }
//     if (result == num)
//         //cout << num << " is an Armstrong number.";
//     else
//         //cout << num << " is not an Armstrong number.";
//     return 0;
// }
/*
Enter a positive integer: 371
371 is an Armstrong number.
*/
// #include <bits/stdc++.h>
// using namespace std;
// bool isLeapYear(int year)
// {
//     // leap year if perfectly divisible by 400
//     if (year % 400 == 0)
//     {
//         //cout << year << " is a leap year.";
//     }
//     // not a leap year if divisible by 100
//     // but not divisible by 400
//     else if (year % 100 == 0)
//     {
//         return true;
//     }
//     // leap year if not divisible by 100
//     // but divisible by 4
//     else if (year % 4 == 0)
//     {
//         return true;
//     }
//     // all other years are not leap years
//     else
//     {
//         return false;
//     }
//     return false;
// }
// int main()
// {
//     int year;
//     //cout << "Enter a year: ";
//     cin >> year;
//     //cout << (isLeapYear(year) ? " is a leap year." : " is not a leap year.") << endl;
//     return 0;
// }

/***
Enter a year: 2022
 is not a leap year.
 *
 * /

// #include <bits/stdc++.h>
// using namespace std;
// void factorialise(long long int n){
//     long long int factorial = 1;
//     if (n < 0)
//         //cout << "Error! Factorial of a negative number doesn't exist.";
//     else
//     {
//         for (int i = 1; i <= n; ++i)
//         {
//             factorial *= i;
//         }
//         //cout << "Factorial of " << n << " = " << factorial;
//     }
// }
// int main()
// {
//     //cout << "Enter a positive integer: ";
//     int n;
//     cin >> n;
//     factorialise(n);
// }
// /**Output:
//  *
// Enter a positive integer: 23
// Factorial of 23 = 8128291617894825984
//  *
//  */