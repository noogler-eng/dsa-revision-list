// Forg jump
// There is a frog on the '1st' step of an 'N' stairs long staircase. 
// The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
// If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
// If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
// Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

#include<iostream>
#include<vector>
using namespace std;

// minimum total energy from 1st stair to nth stair
// time complexity o(2^N)
// space complexity o(N) -> auxillariy space
int frogJump(int n, vector<int> &heights){
    if(n == 1) return 0;
    // for 1 -> 0 and -1 are invalid
    // for 2 -> 1 and 0 are only valid 1 and -1 are not
    if(n == 2) return abs(heights[n-1] -  heights[n-2]);

    int jumpFromOneBehind = abs(heights[n-1] - heights[n-2]) + frogJump(n-1, heights);
    int jumpFromTwoBehind = abs(heights[n-1] - heights[n-3]) + frogJump(n-2, heights);
    return min(jumpFromOneBehind, jumpFromTwoBehind);
}

// optimized approach
// time complexity o(N)
// space complexity o(N) + o(N) -> auxillary space
int helper(int n, vector<int> heights, vector<int> &memo){
    if(n == 1) return memo[n] = 0;
    // for 1 -> 0 and -1 are invalid
    //for 2 -> 1 and 0 are only valid 1 and -1 are not
    if(n == 2) return memo[n] = abs(heights[n-1] -  heights[n-2]);
    if(memo[n] != -1) return memo[n];

    int jumpFromOneBehind = abs(heights[n-1] - heights[n-2]) + helper(n-1, heights, memo);
    int jumpFromTwoBehind = abs(heights[n-1] - heights[n-3]) + helper(n-2, heights, memo);
    return memo[n] = min(jumpFromOneBehind, jumpFromTwoBehind);
}
int frogJump(int n, vector<int> &heights){
   vector<int> memo(heights.size()+1, -1);
   return helper(n, heights, memo);
}