// Subset sums equals to k
// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// For Example :
// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N) -> auxillary space
bool helper(int n, int k, vector<int> &nums, int index, int sum){
    if(index == n) return sum == k; 
    if(sum > k) return false;
    
    // picking 
    // not picking then make sum = 0 first the move forward
    // when it becomes discontinue then break it to 0
    // picking and not picking
    return helper(n, k, nums, index+1, sum+nums[index]) || helper(n, k, nums, index+1, sum);
}

bool isSubsetSumExists(int n, int k, vector<int> &arr){
    return helper(n, k, arr, 0, 0);
}



// optmized version
// time complexity o(N)
// space complexity o(N)
bool helper(int n, int k, vector<int> &nums, int index, int sum, vector<bool> &memo){
    if(index == n) return sum == k; 
    if(sum > k) return memo[index] = false;
    if(memo[index] != false) return memo[index];
    
    // picking 
    // not picking then make sum = 0 first the move forward
    // when it becomes discontinue then break it to 0
    // picking and not picking
    return memo[index] = helper(n, k, nums, index+1, sum+nums[index], memo) || helper(n, k, nums, index+1, sum, memo);
}

bool isSubsetSumExists(int n, int k, vector<int> &arr){
    vector<bool> memo(n+1, false);
    return helper(n, k, arr, 0, 0, memo);
}



// optmized version
// time complexity o(N*K)
// spac complexity o(N*K)
bool isSubsetSumExists(int n, int k, vector<int> &arr){
    vector<vector<bool>> table(n+1, vector<bool>(k+1, false));
    for(int i=0; i<=n; i++) table[i][0] = true;

    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<k+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = table[i-1][j - arr[i-1]] || table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    return table[n][k];
}