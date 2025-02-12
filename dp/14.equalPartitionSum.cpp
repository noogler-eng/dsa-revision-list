// Equal partition sum
// Given an integer array nums, return true if you can partition the array into two subsets 
// such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

// optmized version as tabulation method
// time complexity o(N*N)
// space complexity o(N*N)
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++) sum+=nums[i];

    if(sum % 2 != 0) return false;
    int halfSum = sum / 2;
    vector<vector<bool>> table(nums.size() + 1, vector<bool>(halfSum + 1, false));
    for(int i=0; i<nums.size()+1; i++) table[i][0] = true;

    for(int i=1; i<nums.size()+1; i++){
        for(int j=1; j<halfSum+1; j++){
            if(nums[i-1] <= j){
                table[i][j] = table[i-1][j-nums[i-1]] || table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    return table[nums.size()][halfSum];
}