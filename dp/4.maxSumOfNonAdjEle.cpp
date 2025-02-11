// Maximum sum of non adjacent element
// You are given an array/list of ‘N’ integers. 
// You are supposed to return the maximum sum of the subsequence with the constraint that 
// no two elements are adjacent in the given array/list.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N) -> auxillary space
int helper(vector<int> nums, int n){
    if(n < 0) return 0;
    // making the subsequences 
    // either pick or not pick
    int pick = nums[n] + helper(nums, n-2);
    int notPick = helper(nums, n-1);
    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    return helper(nums, nums.size() - 1);
}

// optimized version
// time complexity o(N)
// space complexity o(N) + o(N) -> auxillary space
int helper(vector<int> nums, int n, vector<int> &memo){
    if(n < 0) return 0;
    if(memo[n] != -1) return memo[n];
    // making the subsequences 
    // either pick or not pick
    int pick = nums[n] + helper(nums, n-2);
    int notPick = helper(nums, n-1);
    return memo[n] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> memo(nums.size()+1, -1);
    return helper(nums, nums.size() - 1, memo);
}