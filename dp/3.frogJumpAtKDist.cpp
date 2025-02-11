// Frog jump at k distance
// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h 
// There is a frog who is initially on Stone 1. 
// He will repeat the following action some number of times to reach Stone N
// If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. 
// Here, a cost of ∣h[i] −h[j]​∣ is incurred, where j is the stone to land on.
// minimum possible total cost incurred before the frog reaches Stone N

#include<iostream>
#include<vector>
using namespace std;

// k jumps from that points are allowed
// n-1, n-2, n-3 ..... n-k
// energy is h[n-1] - h[....from...]
int miniEnergyLost(int n, int k, vector<int> heights){
    if(n == 1) return 0;
    // for 1 -> 0 and -1 are invalid
    // for 2 -> 1 and 0 are only valid 1 and -1 are not
    if(n == 2) return abs(heights[n-1] -  heights[n-2]);

    int mini = INT_MAX;
    for(int i=1; i <= k && n-i >= 1; i++){
        int jump = abs(heights[n-1] - heights[n-1-i]) + miniEnergyLost(n-i, k, heights);
        mini = min(mini, jump);
    }
    return mini;
}

// optmized code
// time complexity o(N * k)
// space complexity o(N) + o(N) -> auxillary space 
int helper(int n, int k, vector<int> heights, vector<int> &memo){
    if(n == 1) return memo[n] = 0;
    // for 1 -> 0 and -1 are invalid
    // for 2 -> 1 and 0 are only valid 1 and -1 are not
    if(n == 2) return memo[n] = abs(heights[n-1] -  heights[n-2]);
    if(memo[n] != -1) return memo[n];

    int mini = INT_MAX;
    for(int i=1; i <= k && n-i >= 1; i++){
        int jump = abs(heights[n-1] - heights[n-1-i]) + helper(n-i, k, heights, memo);
        mini = min(mini, jump);
    }
    return memo[n] = mini;
}
int miniEnergyLost(int n, int k, vector<int> heights){
    vector<int> memo(heights.size()+1, -1);
    return helper(n, k, heights, memo);
}