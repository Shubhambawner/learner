flow of optimisation:
->general recursion
    a TOP-DOWN approach
->memoisation: 
    use ds for storing results
    avoid repetative calls
->tabulation: 
    BOTTOM-UP approach
    use for loop instead of recursion,avoiding space for recursive call stack
->space-optimisation
    instead of using dp to, use only 2 3 variables
    avoid space for dp array

declarative approach or Induction based approach:
## TOP-BOTTOM approach
steps:
1. Creating a function f(i) that will give/return ans for case i
2. co-relate ans for case i ans i-1, 
3. compute answer for case i using ans of case/cases of i-1
4. if i-1 call is a base case :
   * success base case: when desired path/sum/... is obtained
   * failure base case: when array index out of bounds...
   * DP base case: return stored value instead of further recursion
  

## Selective/Constructive method:
* when use: to select all/min/max... combination from string/array given
* Tree is formed:
    a tree of function calls  is formed, as result of picking, calling,not picking and calling again...
* getting the aproach:
    similer to combinatorial problem of finding no of possible ways, i.e. for print all permutations,
    corrosponding mathematical problem is, how are all permutations created, choose 1 of n, then choose 1 of remaning n-1, ...
* using datastructures: 
    temp/t: for maintaining a formed combination
    ds/sum: for pushing temp to it when it fulfills some criteria/ storing max/min/... of t...
* actions: 
    * modify sum/ds for base case;
    * pick: modify temp/t
    * recurse/ call function for i+1
    * unpick: reverse the modification over temp/t
