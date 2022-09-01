## Problem types:
paths/optimal path... in an array

sub-sequence: ordered sequence of elements from array, may or may not be continuous
sub-string: ordered continuous piece of string

## Longest commom sub-sequence among two given strings
allblllc
akkkbkkc -> abc

* how to get the aproach??
  -> express problem in terms of indices, f(i1,i2) here
  -> explore all possiblities, how can f(2,2) be related to f(1,2)/f(2,1)/f(0,0)
  -> no of char in LIS for: s1:0..i1, s2:0..i2
        if s1[i1]==s2[i2] -> 1 + LIS(i1-1, i2-1)
        else try all possiblities i.e. LIS(i1,i2-1), LIS(i1,i2-2), LIS(i1,i2-3... and get max
        so: LIS(i,j) = max( LIS(i-1,j), LIS(i,j-1) )

aproach:
    if(char at i & j in s an t are same) LIS(i,j) = 1+LIS(i-1,j-1) 
    else LIS(i,j) = max( LIS(i-1,j), LIS(i,j-1) )

    base case: i or j is -1, return 0
    i,j can reach -1 in top down, LIS(i,j) means LIS in index [0..i] of s1, [0..j] of s2, OR LIS for substr of size i+1 from start, so, if i=-1, for substr of size 0, that is 0

## longest common sub String

intution: lcsg(i1,i2) = 1+ lcsg(i1-1,i2-1) 
