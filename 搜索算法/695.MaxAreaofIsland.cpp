#include<vector>
#include<iostream>
using namespace std;


int getMax(vector<vector<int>>& grid,int i,int j){
    if(grid[i][j]){
        grid[i][j] = 0;
        return 1+getMax(grid,i-1<0?0:i-1,j)+getMax(grid,i+1>=grid.size()?i:i+1,j)+getMax(grid,i,j+1>=grid[0].size()?j:j+1)+getMax(grid,i,j-1<0?0:j-1);
    }
    return 0;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
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
int main(int argc, char const *argv[])
{
    vector<vector<int>> arr{{1,1,0,0},{0,0,0,0}};
    cout<<maxAreaOfIsland(arr)<<endl;
    return 0;
}
