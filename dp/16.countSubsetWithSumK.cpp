// Count subset with sum k

// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen 
// elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

// important question

#include<iostream>
#include<vector>
using namespace std;

int findWays(vector<int>& arr, int k){
    long long modulo = 1000000007;
	vector<vector<long long>> table(arr.size()+1, vector<long long>(k+1, 0));
    for(int i=0; i<arr.size()+1; i++) table[i][0] = 1;

    for(int i=1; i<arr.size()+1; i++){
        // here we are starting from index 0
        // when sum = 0 and there is i elemnts present
        // as if you think if there is 0 present in array the for 0 there are more then 1 ways that's why
        for(int j=0; j<k+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = (table[i-1][j-arr[i-1]] + table[i-1][j]) % modulo;
            }else{
                table[i][j] = table[i-1][j] % modulo;
            }
        }
    }

    return table[arr.size()][k] % modulo;
}