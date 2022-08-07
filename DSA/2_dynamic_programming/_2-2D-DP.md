## Problem types:
paths/optimal path... in a 2D/3D array

### problem: max path sum for traversing grid top to bottom:
we find max sum for starting from each of the top indices, then compare for max

### modifications at times we are not able to create into TOP-BOTTOM relationship:
1. introduce extra parameter, like lastActivity in ninjas training
2. compute all possible of the

! possiblity of space optimizarion over tabulation on 2D DP/DP on grids/ path finding algo:
### use the provided matrix itself as dp!
instead of space optimization of taking 2 arrays of n size, and swaping them each time, as space optimization over dp matrix...
see if it is possible to use the same given m x n grid as dp matrix.

* easy tabulation/Space-Optimisation, BUT Not Necessary, as space complexicity is grid m x n any way