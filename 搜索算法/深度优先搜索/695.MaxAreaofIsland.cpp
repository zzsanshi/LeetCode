// 深度优先搜索主要有两种实现策略:递归/栈
#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;


int getMax(vector<vector<int>>& grid,int i,int j){
    if(grid[i][j]){
        grid[i][j] = 0;
        return 1+getMax(grid,i-1<0?0:i-1,j)+getMax(grid,i+1>=grid.size()?i:i+1,j)+getMax(grid,i,j+1>=grid[0].size()?j:j+1)+getMax(grid,i,j-1<0?0:j-1);
    }
    return 0;
}
// 使用递归的实现
// 16 ms 21.8 MB
int maxAreaOfIsland_v1(vector<vector<int>>& grid) {
    if(!grid.size()) return 0;
    int maxArea = 0;
    int h = grid.size();
    int w = grid[0].size();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]){
                int tmp = getMax(grid,i,j);
                maxArea = maxArea<tmp?tmp:maxArea;
            }
        }
    }
    return maxArea;
}
// 使用栈的实现
// 24 ms 22.2 MB
int maxAreaOfIsland(vector<vector<int>>& grid) {
    // 下面这个写法就很不错
    int h = grid.size(),w=h?grid[0].size():0;
    int localArea,maxArea = 0;
    stack<pair<int,int>> sk;
    array<array<int,2>,4> direction{{{0,1},{0,-1},{1,0},{-1,0}}};

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]){
                // 设定规则 每次push的时候local+1,置0,在push前就确定这个是个1;
                localArea = 1;
                sk.push({i,j});
                grid[i][j] = 0;

                while(!sk.empty()){
                    auto idx = sk.top();
                    sk.pop();
                    for(auto dir:direction){
                        int x = idx.first+dir[0];
                        int y = idx.second+dir[1];
                        if(x>=0&&x<h&&y>=0&&y<w&&grid[x][y]){
                            localArea++; 
                            sk.push({x,y});
                            grid[x][y] = 0;
                        }
                    }

                }
                maxArea = maxArea<localArea?localArea:maxArea;
            }
        }
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr{{1,1,0,0},{0,0,0,0}};
    cout<<maxAreaOfIsland(arr)<<endl;
    return 0;
}
