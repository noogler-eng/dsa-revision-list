// Ninja and friends
// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. 
// Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and 
// Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). 
// They will always stay inside the ‘GRID’.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of 
// his friends by following the above rules.

// nice question for 3d dp

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2*3^N)
// space complexity o(N*N) -> auxillary stack space;
int helper(vector<vector<int>> &grid, int n, int m, int x, int y1, int y2){

    if( y1 == m || y2 < 0 || y1 < 0 || y2 == m) return INT_MIN;
    if( x == n-1 ) {
        if(y1 == y2) return grid[x][y1];
        return grid[x][y1] + grid[x][y2];
    }

    int chock = y1 == y2 ? grid[x][y1]: grid[x][y1] + grid[x][y2];
    int maxChoco = INT_MIN;
    // movement can happen in directions diagonay or straight
    for (int dy1 = -1; dy1 <= 1; dy1++) { // Alice's moves
        for (int dy2 = -1; dy2 <= 1; dy2++) { // Bob's moves
            maxChoco = max(maxChoco, helper(grid, n, m, x + 1,  y1 + dy1, y2 + dy2));
        }
    }

    return maxChoco + chock;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // here we have to collect the maximum chocklates
    // bob and alice can be on same point, both have common x but change y
    return helper(grid, r, c, 0, 0, grid[0].size()-1);
}


// optmized version
// time complexity o(2*3^N)
// space complexity o(N*N) -> auxillary stack space;
int helper(vector<vector<int>> &grid, int n, int m, int x, int y1, int y2, vector<vector<vector<int>>> &memo){

    if( y1 == m || y2 < 0 || y1 < 0 || y2 == m) return INT_MIN;
    if( x == n-1 ) {
        if(y1 == y2) return grid[x][y1];
        return memo[x][y1][y2] = grid[x][y1] + grid[x][y2];
    }

    if(memo[x][y1][y2] != -1) return memo[x][y1][y2];

    // as x and y values will be change that's hy we have calculated it before
    int chock = y1 == y2 ? grid[x][y1]: grid[x][y1] + grid[x][y2];
    int maxChoco = INT_MIN;
    // movement can happen in directions diagonay or straight
    for (int dy1 = -1; dy1 <= 1; dy1++) { // Alice's moves
        for (int dy2 = -1; dy2 <= 1; dy2++) { // Bob's moves
            maxChoco = max(maxChoco, helper(grid, n, m, x + 1,  y1 + dy1, y2 + dy2, memo));
        }
    }

    return memo[x][y1][y2] = maxChoco + chock;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> memo(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    // here we have to collect the maximum chocklates
    // bob and alice can be on same point, both have common x but change y
    return helper(grid, r, c, 0, 0, grid[0].size()-1, memo);
}