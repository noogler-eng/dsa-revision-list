// Minimum path sum of triangle 
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, 
// you may move to either index i or index i + 1 on the next row.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N*M) -> auxillary space
int helper(vector<vector<int>>& triangle, int n, int x, int y){
    if(x == n || y == x+1) return INT_MAX;
    if(x == n-1) return triangle[x][y];

    // moving down
    int movingDown = helper(triangle, n, x+1, y);
    // moving down + right
    int movingRight = helper(triangle, n, x+1, y+1);
    return min(movingDown, movingRight) + triangle[x][y];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return helper(triangle, n, 0, 0);    
}

// optmized version
// time complexity o(2^N)
// space complexity o(N*M)
int helper(vector<vector<int>>& triangle, int n, int x, int y, vector<vector<int>> &memo){
    if(x == n || y == x+1) return memo[x][y] = INT_MAX;
    if(x == n-1) return memo[x][y] = triangle[x][y];
    if(memo[x][y] != -1) return memo[x][y];

    // moving down
    int movingDown = helper(triangle, n, x+1, y, memo);
    // moving down + right
    int movingRight = helper(triangle, n, x+1, y+1, memo);
    return memo[x][y] = (min(movingDown, movingRight) == INT_MAX ? min(movingDown, movingRight) - triangle[x][y]:  min(movingDown, movingRight))  + triangle[x][y];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return helper(triangle, n, 0, 0, memo);    
}