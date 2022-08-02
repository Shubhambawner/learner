#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T arr, int i = 1);

// //! more efficient way: power set algorithm


//* print all sub-sequences of arr
void getSubsequences(int arr[], int size, int start = 0, list<int>& temp, list<list<int>>& List)
{
    if (start >= size)
    {
        List.push_back(temp);
        return;
    }
    temp.push_back(arr[start]);
    getSubsequences(arr, size, start + 1,temp,List);
    temp.pop_back();
    getSubsequences(arr, size, start + 1,temp,List);
}


/*
! We should always pass the referance to data-structure in the function instead of creating the global datastructure. this is because:
    * if for multiple test cases are run in single program, same data structure will be used for all of them, which is not desired
    * passing a referance dosnt cause any memory usage, because either a way referance to global variables is also stored in stack!
! We should always 
*/
vector<vector<int>> ans;
vector<int> t;
int sum = 0, a = 0;
// subsequence with sum = a, given array of distinct elements.
void getSummingSequence(int arr[], int size, int start = 0)
{
    if (sum == a)
    {
        ans.push_back(t);
        // t.clear();sum=0; //! we dont have to clear temp. variables, they are in fact, used dynamically !!
        return;
    }
    if (size == start)
    {
        // t.clear(); //! we dont have to clear temp. variables, they are in fact, used dynamically !!
        return;
    }

    sum += arr[start];
    t.push_back(arr[start]);
    getSummingSequence(arr, size, start + 1);
    t.pop_back();
    sum -= arr[start];
    getSummingSequence(arr, size, start + 1);
}

// for loop aproach: //* always go for pure recursive one
// multiple times one element can occur in output, i.e. arr is [1 2 3], sum = 5, [1 1 1 2] is valid
void getMultiSummingSequence_loop(int arr[], int size, int start = 0)
{
    if (sum > a)
        return;

    if (sum == a)
    {
        ans.push_back(t);
        // t.clear();sum=0; //! we dont have to clear temp. variables, they are in fact, used dynamically !!
        return;
    }
    if (size <= start)
        return;

    int rev = sum;
    vector<int> revData = t;
    for (; sum <= a;)
    {
        t.push_back(arr[start]);
        sum += arr[start];
        getMultiSummingSequence_loop(arr, size, start);
    }
    sum = rev;
    t = revData;

    getMultiSummingSequence_loop(arr, size, start + 1);
}

// pure recursion approach: //* always go for pure recursive one
void getMultiSummingSequence_pure_rec(int arr[], int size, int start = 0)
{
    if (sum > a)
    {
        return;
    }

    if (sum == a)
    {
        ans.push_back(t);
        // t.clear();sum=0; //! we dont have to clear temp. variables, they are in fact, used dynamically !!
        return;
    }
    if (size <= start)
        return;

    if (sum <= a) //* never implement the for loop with
    {
        t.push_back(arr[start]);
        sum += arr[start];
        getMultiSummingSequence_pure_rec(arr, size, start);
        sum -= arr[start];
        t.pop_back();
    }

    getMultiSummingSequence_pure_rec(arr, size, start + 1);
}

// https://leetcode.com/problems/combination-sum-ii/
// array may contain duplicates, 
// but each reasulting combination in ans must be unique, arr = [1, 2, 1], sum = 3, ans = [1,2] ( only one unique combination )
// candidates is sorted initially
list<int>& temp;
void combinationSum2(int target, vector<int> candidates, int starter = 0)
{
    if (target == 0)
    {
        // if(!check.count(temp)){ check.insert(temp);}
        ans.push_back(t);
        return;
    }
    if (target < 0)
    {
        return;
    }

    if (starter >= candidates.size())
        return;

    temp.push_back(candidates[starter]);
    combinationSum2(target - candidates[starter], candidates, starter + 1);
    temp.pop_back();

    //! skipping the cases that cause the repetations
    while (starter + 1 < candidates.size() && candidates[starter] == candidates[starter + 1])
        starter++;

    combinationSum2(target, candidates, starter + 1);
}


int main()
{
    int arr[] = {1, 2, 3};
    // getSubsequences(arr, 5);
    // print(List);
    a = 4;
    // getConditionalSequence(arr, 7);
    vector<int> candidates = {1, 2,3,1};
    combinationSum2(a, candidates);
    print(ans);
    cout << "\nend\n";
}

// utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
template <class T>
void print(T arr, int i)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout << i++ << "---- ";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " ";
        }
        cout << '\n';
    }
}

/*
sub-set: [3,1] is sub set of [1,2,3,4,5], NO duplicates
sub-sequence: in same order as array. [1,2,2,5] is sub-sequence of [1,2,2,3,4,5]
contigeous: in same order and continuous, i.e. [1,2,3] is contigeous sub-sequence of [1,2,3,4,5,6], but not [1,2,4]
sub-array:
permutation:
combination:
*/