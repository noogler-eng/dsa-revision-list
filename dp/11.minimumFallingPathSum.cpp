// Minimum falling path sum
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and 
// chooses the element in the next row that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

#include<iostream>
#include<vector>
using namespace std;
int helper(vector<vector<int>>& matrix, int n, int x, int y){
    if(x == n || y == n || y < 0 || x < 0) return INT_MAX;
    if(x == n-1) return matrix[x][y];

    // moving down, moving diagonally right, moving diagonally left
    int movingDown = helper(matrix, n, x+1, y);    
    int movingRight = helper(matrix, n, x+1, y+1);
    int movingLeft = helper(matrix, n, x+1, y-1);

    return min(movingDown, min(movingRight, movingLeft));
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    // we can start from any points like any cell
    int miniAns = INT_MAX, n = matrix.size();
    for(int i=0; i<n; i++){
        miniAns = min(miniAns, helper(matrix, matrix.size(), 0, i));
    }
    return miniAns;
}


// optmized approach
// time complexity o(N*N)
// space complexity o(N*N)
int helper(vector<vector<int>>& matrix, int n, int x, int y, vector<vector<int>> &memo){
    if(x == n || y == n || y < 0 || x < 0) return INT_MAX;
    if(x == n-1) return memo[x][y] = matrix[x][y];
    if(memo[x][y] != INT_MIN) return memo[x][y];

    // moving down, moving diagonally right, moving diagonally left
    int movingDown = helper(matrix, n, x+1, y, memo);    
    int movingRight = helper(matrix, n, x+1, y+1, memo);
    int movingLeft = helper(matrix, n, x+1, y-1, memo);

    return memo[x][y] = min(movingDown, min(movingRight, movingLeft)) == INT_MAX ? INT_MAX: min(movingDown, min(movingRight, movingLeft)) + matrix[x][y];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    // we can start from any points like any cell
    vector<vector<int>> memo(matrix.size(), vector<int>(matrix.size(), INT_MIN));
    int miniAns = INT_MAX, n = matrix.size();
    for(int i=0; i<n; i++){
        miniAns = min(miniAns, helper(matrix, matrix.size(), 0, i, memo));
    }
    return miniAns;
}
