// Climbing stairs
// You have been given a number of stairs. Initially, 
// you are at the 0th stair, and you need to reach the Nth stair.
// Each time, you can climb either one step or two steps.
// You are supposed to return the number of distinct ways you can climb 
// from the 0th step to the Nth step.

#include<iostream>
#include<vector>
using namespace std;

// on each stair we have choice either climb 1 or climb 2
// count means add
// time complexity o(2^N)
// space complexity o(N) -> auxillary space
int countDistinctWays(int n) {
    if(n == 1 || n == 2) return n;
    return countDistinctWays(n-1) + countDistinctWays(n-2);
}

// optmized version 
// time complexity o(N)
// space complexity o(N) + o(N) -> auxillary space
int helper(int n, vector<int> &memo){
    if(n == 1 || n == 2) return memo[n] = n;
    if(memo[n] != -1) return memo[n];
    return memo[n] = helper(n-1, memo) + helper(n-2, memo);
}
int countDistinctWays(int n) {
    vector<int> memo(n+1, -1);
    return helper(n, memo);
}


// optimized version
// time complexity o(N)
// spacec complexity o(N)
int countDistinctWays(int n) {
    if(n == 0 || n == 1 || n == 2) return n;
    vector<int> memo(n+1, 0);
    memo[1] = 1;
    memo[2] = 2;
    for(int i=3; i<n+1; i++) memo[i] = memo[i-1] + memo[i-2];
    return memo[n];
}
