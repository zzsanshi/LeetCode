// 这道题我第一个想法是用并查集做 或者使用深搜
#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;

// 使用dfs+递归的形式
// ---错误的思路,不能记录根本没有交互的节点---
void dfsDel(vector<vector<int>>& isConnected,int i,int j){
    if(i!=j&&isConnected[i][j]){
        isConnected[i][j] = 0;
        for(auto idx:{i,j}){
            for(int z=0;z<isConnected.size();z++){
                dfsDel(isConnected,idx,z);
                dfsDel(isConnected,z,idx);
            }
        }
    }
}

int findCircleNum_v0(vector<vector<int>>& isConnected) {
    // 使用695学到的提取数组范围的写法,划掉,肯定是一样大的还算个啥...
    int h = isConnected.size(),w=h;
    int grop = 0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i!=j&&isConnected[i][j]){
                grop++;
                dfsDel(isConnected,i,j);
            }
        }
    }
    return grop;
}

// 正确的递归思路是记录被访问节点
void dfsVis(vector<vector<int>>& isConnected,int i){
    for(int idx=0;idx<isConnected.size();idx++){
        cout<<i<<" "<<idx<<endl;
        if(isConnected[i][idx]){
            isConnected[i][idx] = 0;
            dfsVis(isConnected,idx);
        }
    }
}

int findCircleNum_v1(vector<vector<int>>& isConnected) {
    // 使用695学到的提取数组范围的写法,划掉,肯定是一样大的还算个啥...
    int h = isConnected.size();
    int grop = 0;
    for(int i=0;i<h;i++){
        // 只搜上半区减少搜索范围,在递归方法中也从i开始扫描
        // 这里用小于等于就不用判断孤岛了
        for(int j=0;j<=i;j++){
            if(isConnected[i][j]){
                grop++;
                cout<<i<<endl;
                dfsVis(isConnected,i);
            }
        }
    }

    return grop;
}
int main(){
    vector<vector<int>> t{{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum_v1(t);
    string s = "AAB";
}