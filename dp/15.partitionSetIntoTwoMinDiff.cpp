// Partition set into two with Minimum absolute difference
// You are given an array 'arr' containing 'n' non-negative integers.

// Your task is to partition this array into two subsets such that the absolute difference 
// between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.

// important question
// time complexity o(N*N)
// space complexity o(N*N)
#include<iostream>
#include<vector>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n){
    // array containg non negative integers
    // x + y = sum
    // x - y = minimum
    // 2*x = sum + minimum
    // mini = 2 * x - sum
    // making it the minimum

    int sum = 0;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];
    int half = sum / 2;
    vector<vector<bool>> table(n+1, vector<bool>(n+1, false));

    vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= half; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int bestS1 = 0;
    for (int j = half; j >= 0; j--) {
        if (dp[n][j]) {
            bestS1 = j;
            break;
        }
    }

    return abs(sum - 2 * bestS1);
}