#include <vector>
#include <iostream>
#include <algorithm>
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
// HOT
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


// 堆排序
// TODO

// ---归并排序---
// 归并排序
void merge(vector<int> &arr,int left,int right){
    int l = left;
    vector<int> sorted;
    int mid = (left+right)>>1;
    int secondHead = mid + 1;
    while(left<=mid&&secondHead<=right){
        if(arr[left]<arr[secondHead]){
            sorted.emplace_back(arr[left++]);
        }
        else{
            sorted.emplace_back(arr[secondHead++]);
        }
    }
    while(left<=mid){
        sorted.emplace_back(arr[left++]);
    }
    while(arr[secondHead]<right){
        sorted.emplace_back(arr[secondHead++]);
    }
    for(auto ai:sorted){
        arr[l++] = ai;
    }
}

void MergeSort(vector<int> &arr,int left,int right){
    if(left<right){
        int mid = (left+right)>>1;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        merge(arr,left,right);
    }
}

// ---非比较排序---
// 计数排序
void CountSort(vector<int> &arr,int left,int right){
    int maxn=arr[0],minn=arr[0];
    for(auto ai:arr){
        if(ai>maxn) maxn=ai;
        if(ai<minn) minn=ai;
    }
    vector<int> sorted(maxn-minn+1,0);
    for(auto ai:arr){
        sorted[ai-minn]++;
    }
    int pos=0;
    for(int i=0;i<sorted.size();i++){
        while(sorted[i]){
            arr[pos++] = i+minn;
            sorted[i]--;
        }
    }
}
// 桶排序
// TODO

// 基数排列
// TODO 先排个位再排更高位，每次排序的时候都开10长度的数组就行

int main(){
    vector<int> arr{1,3,5,2,-1,4,2};
    CountSort(arr,0,arr.size()-1);
    cout<<arr<<endl;
    sort(arr.begin(),arr.end(),[](int x,int y){
        return x;
    });
}