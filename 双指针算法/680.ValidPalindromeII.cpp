#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 如果发现不匹配就所有各去掉一个试试是不是完全回文字
// 60 ms 22.7 MB
bool Palindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
bool validPalindrome(string s) {
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return Palindrome(s.substr(i,j-i))||Palindrome(s.substr(i+1,j-i));
        }
    }
    return true;
}

// TODO 有待优化

int main(){
    cout<<validPalindrome("aydmda");
}