// Ninjas trainning 
// A Ninja has an ‘N’ Day training schedule. 
// He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
// There are merit points associated with performing an activity each day. 
// The same activity can’t be performed on two consecutive days. 
// We need to find the maximum merit points the ninja can attain in N Days.

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N*N)
// space complexity o(N*N) -> auxillary space
int helper(vector<vector<int>> &points, int x, int y, int n, int prev_y){
    // if selecting the any cell then move forward but not select the prev one  
    // coloumn must not be same
    if(x >= n || y >= n) return 0;
    // picking and notpicking
    // if picking then moving to next row and starting from coloum = 0
    int picking = 0;
    if(prev_y != y){
        // we have to this only when we are selecting, not in all cases
        picking = helper(points, x+1, 0, n, y) + points[x][y];
    }

    // if not picking then moving to the next coloumn
    int notPicking = helper(points, x, y+1, n, prev_y);
    return max(picking, notPicking);
}

int ninjaTraining(int n, vector<vector<int>> &points){
    return helper(points, 0, 0, n, -1);
}



// time complexity o(N)
// space complexity o(N*N)
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> memo(n+1, vector<int>(n+1, 0));
    
    for(int i=1; i<=n; i++){
        // if selecting the coloumn 0 then we have to take the max of rest of two coloumn
        memo[i][0] = points[i-1][0] + max(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = points[i-1][1] + max(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = points[i-1][2] + max(memo[i-1][0], memo[i-1][1]);
    }

    return max(max(memo[n][0], memo[n][1]), memo[n][2]);
}
