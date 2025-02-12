// Assign cookies

// Assume you are an awesome parent and want to give your children some cookies. 
// But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
// and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, 
// and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include<iostream>
#include<vector>
using namespace std;

// this is not an optmized version
// optmized version is by greedy approach
int findContentChildren(vector<int>& g, vector<int>& s) {
    // here we are not sorting
    vector<vector<int>> table(g.size() + 1, vector<int>(s.size() + 1, 0));
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // here g is the greed factor
    // here s is the cookies size
    for (int i = 1; i < g.size() + 1; i++) {
        for (int j = 1; j < s.size() + 1; j++) {
            if (s[j-1] >= g[i-1]) {
                // cookies can be assign or leave
                // we move form both boys and cookies
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                // cookies cannot be assign
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table[g.size()][s.size()];
}