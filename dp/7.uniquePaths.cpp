// Unique Paths
// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths 
// that the robot can take to reach the bottom-right corner.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N) -> auxillary space
int helper(int m, int n, int x, int y){
    if(x == m || y == n) return 0;
    if(x == m-1 && y == n-1) return 1;

    // either moving to the right or moving to the down
    // we have to count total paths -> sum
    int movingDown = helper(m, n, x+1, y);
    int movingRight = helper(m, n, x, y+1);
    return movingDown + movingRight;
}

int noOfUniquPaths(int m, int n){
    // we have an grid of m * n
    return helper(m, n, 0, 0);
}


// optimized approach
// time complexity o(2^N)
// space complexity o(N*M) + o(N*M) - auxillary stack space
int helper(int m, int n, int x, int y, vector<vector<int>> &memo){
    if(x == m || y == n) return 0;
    if(x == m-1 && y == n-1) return memo[x][y] = 1;
    if(memo[x][y] != -1) return memo[x][y];

    // either moving to the right or moving to the down
    // we have to count total paths -> sum
    int movingDown = helper(m, n, x+1, y, memo);
    int movingRight = helper(m, n, x, y+1, memo);
    return memo[x][y] = movingDown + movingRight;
}

int noOfUniquPaths(int m, int n){
    // we have an grid of m * n
    // we have x and y two chaning variables
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return helper(m, n, 0, 0, memo);
}


// most optimized appraoch
// time complexity o(M*N)
// space complexity o(M*N)
int uniquePaths(int m, int n) {
    vector<vector<int>> table(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) table[0][i] = 1;
    for (int i = 0; i < m; i++) table[i][0] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    return table[m - 1][n - 1];
}