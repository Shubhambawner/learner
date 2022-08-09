

## Problem types:
subset of array summing to k, pick and not pick,
* generally: limitation: array[i] is not huge in size, generally < 100, <1000 or so...


## recursive function: 

    f(index,target) gives:
    number of subsets with sum as target, int the array starting from index ind to n-1
    so, dp[ind][target] stores number of subsets with sum as target, int the array starting from index ind to n-1

    approach: pick and not pick style:
    f(i, target) = f(i+1,target) + f(i+1, target - arr[i])
    i.e. take or not take element at i

    base case: ind==n, i.e. whole array has been traversed, so now if target gets completely chased, i.e. target==0, the shosen subset gives sum target and so return 1, else return 0