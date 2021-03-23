#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &matrix,int x,int y){
    int m = matrix.size(),n = matrix[0].size();
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto tmp = q.front();
        if(matrix[tmp.first][tmp.second]){
            q.pop();
            if(tmp.first>0) q.push({tmp.first-1,tmp.second});
            if(tmp.first<m-1) q.push({tmp.first+1,tmp.second});
            if(tmp.second>0) q.push({tmp.first,tmp.second-1});
            if(tmp.second<n-1) q.push({tmp.first,tmp.second+1});
        }
        else{
            return abs(tmp.first-x)+abs(tmp.second-y);
        }
    }
}

// 思路 1 bfs
// 168 ms 113.9 MB
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    vector<vector<int>> out(m,vector<int>(n,0)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    // 如果是1则需要搜索
                    out[i][j] = bfs(matrix,i,j);
                }
            }
        }
    return out;
}

// 思路2 dp
// 受到思路1中dfs可以利用坐标得出距离的结论
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                dp[i][j] = matrix[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1]+matrix[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j]+matrix[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }
    }
    return dp;
}