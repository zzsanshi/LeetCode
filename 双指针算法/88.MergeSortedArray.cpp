#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;
// 这道题就是一道归并排序 ，但是大佬们有从后面往前插就不用再开辟新空间的方案

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0,j=0,p=0;
    int res[m+n];
    while(i<m&&j<n){
        if(nums1[i]<=nums2[j]){
            res[p++]=nums1[i++];
        }else{
            res[p++]=nums2[j++];
        }
    }
    if(p<m+n){
        while(i<m){
            res[p++] = nums1[i++];
        }
        while(j<n){
            res[p++] = nums2[j++];
        }
    }
        for(int i=0;i<m+n;i++){
            cout<<res[i];
        nums1[i] = res[i];
    }
}

// TODO 新方案 不用开辟额外空间

int main(){
    vector<int> a{0};
    vector<int> b{1};
    merge(a,0,b,1);
    cout<<a[0];
}