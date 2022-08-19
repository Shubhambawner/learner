# DP on subsets/substrings
here we are given a sequence, and a subsequence/sub-array with some requirments is required, so, we check the requirments for all possible subsets using ``take-not take pattern``

## subset with sum k: Problem types:
subset of array summing to k, pick and not pick,
* generally: limitation: array[i] is not huge in size, generally < 100, <1000 or so...


## recursive function: 

    f(index,target) gives:
    number of subsets with sum as target, int the array starting from index ind to 0
    so, dp[ind][target] stores number of subsets with sum as target, in the array starting from index ind to 0

    approach: pick and not pick style: ( recurance relation )
    f(i, target) = f(i-1,target) + f(i-1, target - arr[i])
    i.e. take or not take element at i


    base case: ind==0, i.e. whole array has been traversed, so now if target gets completely chased, i.e. target==0, the shosen subset gives sum target and so return 1, else return 0

## knapsack type problems:
1. instead of sequence of numbers, we have sequence of pairs, i.e. <weight,value>
to find: subsequence with max value s.t. weight<= w, 

    f(ind,W) gives max. value possible for array of <weight,value> from 0 to index ind, where max weight is W
    
    approach: pick and not pick bag at index ind: 
    not take = f(ind-1,W), 
    if can take, i.e. W> weight[ind] -> take = f(ind-1,W-weight[ind]) + value[ind]
    return max(take,notTake)

    not a base case: W <=0 care is taken not to call f s.t. w<=0. so not a case
    base case: index==-1; return 0, here f(ind,w) is for array of size ind+1, so f(-1 ,w) is for array of size 0, so max valu possible is 0

2. coin exchange: given coins denomination array, to find max. number of coins needed to make change of r rupees, can take each coin any no. of times

    f(ind,V) gives max. coins needed for reaching value V in array of index 0 to ind,

    approach: pick and not pick ``can pick element at same index multiple times``
    not take: f(ind-1,V) // move to next index
    if can take same index, V>value[ind] -> take = f(ind,V-value[ind])
    return max

    base case: index==-1; return 0, here f(ind,v) is for array of size ind+1, so f(-1 ,v) is for array of size 0, so max valu possible is 0
    