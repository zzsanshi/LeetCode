#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;
// 
// 88 ms 23.2 MB
vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
void dfsFlow(vector<vector<int>> &matrix,vector<vector<bool>> &ans,int idx,int jdx){
    int h = matrix.size(),w=matrix[0].size();
    ans[idx][jdx] = true;
    for(auto d:dir){
        int x = idx+d[0];
        int y = jdx+d[1];
        if(x>=0&&x<h&&y>=0&&y<w&&!ans[x][y]){
            // cout<<x<<" "<<y<<" "<<idx<<" "<<jdx<<endl;
            if(matrix[x][y]>=matrix[idx][jdx])
            dfsFlow(matrix,ans,x,y);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    int h = matrix.size();
    vector<vector<int>> out;
    if(!h){
        return out; 
    }
    int w = matrix[0].size();
    vector<vector<bool>> ans(h,vector<bool>(w,false));
    vector<vector<bool>> ans2(h,vector<bool>(w,false));
    for(int i=0;i<h;i++){
        // 左侧
        // cout<<"左侧"<<endl;
        dfsFlow(matrix,ans,i,0);
        // 右侧
        // cout<<"右侧"<<endl;
        dfsFlow(matrix,ans2,i,w-1);
    }
    for(int i=0;i<w;i++){
        // 上侧
        dfsFlow(matrix,ans,0,i);
        // 下侧
        dfsFlow(matrix,ans2,h-1,i);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(ans[i][j]&&ans2[i][j]){
                out.push_back({i,j});
            }
        }
    }
    return out;
}

int main(){
    vector<vector<int>> test{{1,1},{1,1},{1,1}};
    pacificAtlantic(test);
}