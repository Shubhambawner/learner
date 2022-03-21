#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> intervals) {
        vector<vector<int>>  ans;
        bool flag[10000]={false};
        int arr[10000]={0};
        for(int i = 0; i<intervals.size(); i++){
            arr[intervals[i][0]]++;
            arr[intervals[i][1]]--;
            if(intervals[i][0]==intervals[i][1]) {
                flag[intervals[i][0]]=true;//cout<<i<<"--\n";
            }
        }
        int temp = 0;
        vector<int>t;
        for(int i = 0; i<10000; i++){
            if(temp == 0 && arr[i]>0){
                t.push_back(i);
            }
            temp+=arr[i];
            if(temp == 0 && arr[i]<0){
                t.push_back(i);
                ans.push_back(t);
                t.pop_back();
                t.pop_back();
                
            }
            //if(i<10){cout<<i<<" "<<temp<<" "<<flag[i]<<"\n";}
            if(flag[i] && temp==0){
                t.push_back(i);
                t.push_back(i);
                ans.push_back(t);
                t.pop_back();
                t.pop_back();
            }
        }
        return ans;
    }

    int main(){
        vector<vector<int>> intervals;
        intervals.push_back({1,4});
        intervals.push_back({9,9});
        merge(intervals);
    }
// vector<int> partitionLabels(string s) {
//         unordered_set<char> front;
//         unordered_set<char> back;
//         int n = s.size();
//         int arr[n]={0};
        
//         for(int i = 0; i<n; i++){
            
//             if(front.find(s[i])==front.end()){
//                 arr[i]=1;
//                 front.insert(s[i]);
//             }
//         }
//         for(int i = n-1; i>=0; i--){
            
//             if(back.find(s[i])==back.end()){
//                 arr[i]-=1;
//                 back.insert(s[i]);
//             }
//         }
        
//         int temp=0, len=0 ;
//         vector<int> ans;
//         for(int i = 0; i<n;i++){
//             temp+=arr[i];
//             len++;
//             if(temp==0){
//                ans.push_back(len);
//                 len=0;
//             }
//         }
//         return ans;
//     }


// int main(){
    
//     vector<int>a = {1,2,3,4,5};
//     vector<int> *A = &a;
//     // cout<<A<<" "<<&a<<endl;
//     // cout<<A->at(0)<<endl;
//     // cout<<&a[0]<<" "<<&a[0]+1<<endl;
//     // cout<<*(&a[0])<<" "<<*(&a[0]+1)<<endl;

//     vector<vector<int>> b ;
//     b.push_back(a);
//     b.push_back({2,3});
//     b.push_back({3,4});
//     cout<<(&(b[0]).at(1))<<endl;
//     cout<<&(b[0].at(1))<<endl;
//     cout<<*&(b[0].at(1))<<endl;
//     cout<<(&b[0])<<endl;
//     cout<<(&b.at(0))<<endl;
//     cout<<A<<endl;
//     cout<<&a<<endl;
//     //cout<<*(&b[0])<<" "<<*(&b[0]+1)<<endl;
// }
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <bits/stdc++.h>
// using namespace std;

// int n;int p;int k;
// int ans = 0;
// int G = 1000000007;
// int data[10]={0,0,0,0,0,0,0,0,0,0};

// int temp = 0;
// void getSubsequences(int start = 0)
// {
//     if (start >= 10)
//     {
//         if(temp%k==p) ans+= temp;
//         ans = ans%G;
//         return;
//     }
//     temp*=data[start];
//     temp = temp%G;
//     getSubsequences( start + 1);
//     temp/=data[start];
//     temp = temp%G;
//     getSubsequences( start + 1); 
// }

// int main() {
//     cin>>n;
//     cin>>p;
//     cin>>k;
//     int arr[n];
    
//     for(int i=0; i<n;i++){
//         cin>>arr[i];
//         data[arr[i]%k]++;
//     }
//     getSubsequences();
//     cout<<ans;
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     return 0;
// }


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     int n; cin>>n;
//     int arr[n];
//     for(int i = 0; i<n;i++){
        
//         cin>>arr[i];
//     }
//     int x = arr[0];
//     for(int i = 0; i<n;i++){
//         if(x==2){ cout<<i+1;return 0;}
//         x = arr[x-1];
//     }
//     cout<<-1;
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> ans;
//         int n = numbers.size();
//         for(int i=0; i<n;i++){
//             int d = abs(target - numbers[i]);
//             cout<<numbers[i]<<" "<<d<<" "<<binary_search(&numbers[0], &numbers[n], d)<<"\n";
//             if(binary_search(&numbers[0], &numbers[n], d)){
//                 ans.push_back(i+1);
//                 target = d;
//                 break;
//             }
//         }
        
//         for(int i=0; i<n;i++){
//             if(numbers[i]==target) {
//                 ans.push_back(i+1);
//                 break;
//             }
//         }
//         return ans;
//     }
//     int main(){
//         vector<int> a = {20,210,400};
//         twoSum(a, 420);
//     }
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