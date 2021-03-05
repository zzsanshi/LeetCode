#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void Swap(T &x,T &y){
    T tem = x;
    x = y;
    y = tem;
}
template<typename T>
ostream& operator<<(ostream &os,vector<T> t){
    auto s=t.begin(),e=t.end();
    while(s!=e){
        os<<*s<<" ";
        s++;
    }
    return os;
}

// ---交换排序算法---
// 冒泡排序 
void BubbleSort(vector<int> &arr,int begin,int end){
    for(int i=begin;i<end;i++){
        for(int j=begin;j<end-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }    
}

// 快速排序 左闭右闭
int Partition(vector<int> &arr,int left,int right){
    // 这里使用第一个值作为起始flag
    int temp = arr[left];
    while(left<right){
        while(left<right && arr[right]>=temp) right--;
        arr[left] = arr[right];
        while(left<right && arr[left]<=temp) left++;
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return  left;
}
void QuickSort(vector<int> &arr,int left,int right){
    if(left<right){
        int mid = Partition(arr,left,right);
        QuickSort(arr,mid+1,right);
        QuickSort(arr,left,mid-1);
    }

}

// ---插入排序---

// 简单插入排序
void InsertionSort(vector<int> &arr,int left,int right){
    int current,pos;
    for(int i=1;i<=right;i++){
        current = arr[i];
        pos = i;
        while(pos-1>0&&current<arr[pos-1]){
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = current;
    }
}
// 希尔排序 
// TODO

// ---选择排序---

// 简单选择排序
void SelectionSort(vector<int> &arr,int left,int right){
    int pos;
    for(int i=0;i<right;i++){
        pos=i;
        for(int j=i;j<=right;j++){
            if(arr[j]<arr[pos]){
                pos = j;
            }
        }
        swap(arr[i],arr[pos]);
    }
}

// ---归并排序---
// 归并排序






int main(){
    vector<int> arr{1,3,5,2,4,2};
    SelectionSort(arr,0,arr.size()-1);
    cout<<arr;
}
// 堆排序
// TODO

