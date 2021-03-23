#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 二维数组从左上角到右下角 只能向右或者向下，最短路径和
// 8 ms 9.9 MB
int minPathSum(vector<vector<int>>& grid){
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                dp[i][j] = grid[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1]+grid[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j]+grid[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}