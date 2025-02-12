// Count partitions

// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. 
// Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the 
// difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
// 1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
// 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
// Refer to the example below for clarification.
// Note that the sum of the elements of an empty subset is 0.

// s1 + s2 = sum
// s1 - s2 = D
// 2*s1 = sum + D
// s1 = sum + D

#include<iostream>
#include<vector>
using namespace std;

// optmized version - tabulation method
// time complexity o(N*N)
// space complexity o(N*N)
int countPartitions(int n, int d, vector<int> &arr) {
    int mod = 1000000007;
    int sum = 0;
    for(int i=0; i<n; i++) sum+=arr[i];
    if((sum + d) % 2 != 0) return 0;
    int s1 = (d + sum ) / 2;

    vector<vector<long long>> table(n+1, vector<long long>(s1+1, 0));
    table[0][0] = 1;    

    for(int i=1; i<n+1; i++){
        for(int j=0; j<s1+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = (table[i-1][j-arr[i-1]] + table[i-1][j]) % mod;
            }else{
                table[i][j] = (table[i-1][j]) % mod;
            }
        }
    }

    return (table[n][s1]) % mod;
}