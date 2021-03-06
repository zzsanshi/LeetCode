#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// 这道题就是347题的变形，347题使用的桶排序，这个由于要一排到底其实用啥排序都无所谓，就写个快排练习
// 12 ms 7.9 MB
int Partition(vector<pair<char,int>> &vec,int left,int right){
    auto tmp = vec[left];
    while(left<right){
        while(left<right&&vec[right].second>=tmp.second) right--;
        vec[left] = vec[right];
        while(left<right&&vec[left].second<=tmp.second) left++;
        vec[right] = vec[left];
    }
    vec[left] = tmp;
    return left;
}
void QuickSort(vector<pair<char,int>> &vec,int left,int right){
    if(left<right){
        int mid = Partition(vec,left,right);
        QuickSort(vec,left,mid-1);
        QuickSort(vec,mid+1,right);
    }
}

string frequencySort(string s) {
    unordered_map<char,int> hm;
    for(auto c:s){
        hm[c]++;
    }
    // 对hm排队
    vector<pair<char,int>> vec(hm.begin(),hm.end());
    QuickSort(vec,0,vec.size()-1);
    int loc = 0;
    for(int i=vec.size()-1;i>=0;i--){
        while(vec[i].second){
            s[loc++] = vec[i].first;
            vec[i].second--;
        }
    }
    return s;
}