// House Robber
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed.
// All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int> nums, int index, int n){
    if(index >= n) return 0;
    
    // eiter selecting or not
    int picking = helper(nums, index + 2, n) + nums[index];
    int Notpicking = helper(nums, index + 1, n);
    return max(picking, Notpicking);
}

int maximumAmountOfMoneyRobbed(vector<int> nums){
    // houses in the curcular loop which can be roobed from any non adjacent house
    int startingWithOne = helper(nums, 0, nums.size()-1);
    int startingWithTwo = helper(nums, 1, nums.size());
    return max(startingWithOne, startingWithTwo);
}


// time commplexity o(2^N)
// space complexity o(N)
#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int> nums, int index, int n, vector<int> &memo){
    if(index > n) return 0;
    if(index == n) return memo[index] = 0;
    if(memo[index] != -1) return memo[index];
    
    // eiter selecting or not
    int picking = helper(nums, index + 2, n, memo) + nums[index];
    int Notpicking = helper(nums, index + 1, n, memo);
    return memo[index] = max(picking, Notpicking);
}

int maximumAmountOfMoneyRobbed(vector<int> nums){
    if(nums.size() == 1) return nums[0];

    // houses in the curcular loop which can be roobed from any non adjacent house
    vector<int> memo1(nums.size() + 1, -1);
    vector<int> memo2(nums.size() + 1, -1);

    int startingWithOne = helper(nums, 0, nums.size()-1, memo1);
    int startingWithTwo = helper(nums, 1, nums.size(), memo2);
    return max(startingWithOne, startingWithTwo);
}