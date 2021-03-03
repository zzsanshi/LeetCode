// 该数是否能划分成两个数平方之和
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 最初的想法是构建一个从零开始的平方列表，然后对这个列表进行双指针搜索
// 12 ms 24.7 MB
bool judgeSquareSum_v1(int c) {
    vector<long> us;
    for(long i=0;i<sqrt(c)+1;i++){
        us.emplace_back(i*i);
    }
    auto si = us.begin(),ei = us.end()-1;
    while(ei-si>=0){
        if(*si+*ei==c){
            return true;
        }else if (*si+*ei<c)
        {
            si++;
        }else{
            ei--;
        }
    }
    return false;
}

// 在算法1的基础上去除不必要的计算计算，扫描的时候再算平方值
// 4 ms 5.8 MB
bool judgeSquareSum_v2(int c) {
    long i=0,j = sqrt(c)+1;
    while(i<=j){
        int tem = i*i+j*j;
        if(tem==c){
            return true;
        }else if (tem<c)
        {
            i++;
        }else{
            j--;
        }
    }
    return false;
}

// 拿哈希表直接莽看起来确实不太行
// 292 ms 60.9 MB
bool judgeSquareSum_v3(int c) {
    int i=0,j = sqrt(c);
    unordered_set<int> us;
    while(i<=j){
        long tmp = i*i;
        us.emplace(tmp);
        if(us.find(c-tmp)!=us.end()){
            return true;
        }
        i++;
    }
    return false;
}

// 继续在算法2上改，更有效地利用计算平方的结果 （x+1）^2=x^2+x<<1+1;（x-1）^2=x^2-x<<1+1;
// 0 ms 5.8 MB
bool judgeSquareSum_v2(int c) {
    int i=0,j = sqrt(c);
    long jj = j*j,ii=0;
    while(i<=j){
        int tem = ii+jj-c;
        if(tem==0){
            return true;
        }else if (tem<0)
        {
            ii = ii+(i<<1)+1;
            i++;
        }else{
            jj = jj-(j<<1)+1;
            j--;
        }
    }
    return false;
}