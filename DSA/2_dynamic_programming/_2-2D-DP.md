## Problem types:
paths/optimal path... in a 2D/3D array

### problem: max path sum for traversing grid top to bottom:
we find max sum for starting from each of the top indices, then compare for max

### modifications at times we are not able to create into TOP-BOTTOM relationship:
1. introduce extra parameter, like lastActivity in ninjas training
2. compute all possible of the

! possiblity of space optimizarion over tabulation on 2D DP/DP on grids/ path finding algo:
### use the provided matrix itself as dp! (iff the given grid can be mutateted)
instead of space optimization of taking 2 arrays of n size, and swaping them each time, as space optimization over dp matrix...
see if it is possible to use the same given m x n grid as dp matrix.

* easy tabulation/Space-Optimisation, BUT Not Necessary, as space complexicity is grid m x n any way

direction of flow of recursion:
### which side to choose as top, and which as bottom? (in top-bottom paradigm)
-> depends on given grid as well, if grid is given as grid[0,0] is starting point, then recursion will have: top-down approach as from 0,0 -> n-1,m-1 -> 0,0
and tabulation as: from n-1,m-1 -> 0,0
and anser is dp[0,0] or rc(0,0)

