// 滑动窗口的题
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 匹配串有两个同样的值，被匹配串也要有那么多个值对应
string minWindow_v0(string s, string t) {
    unordered_map<char,int> um;
    unordered_map<char,int> window;
    for(auto c:t){
        um[c]++;
        window[c]=0;
    }
    int match=um.size(),matched=0;
    int i=0,j=0,minlen=0x7FFFFFFF,pos=0;
    while(i<=j&&j<s.size()){
        cout<<i<<" "<<j<<" "<<matched<<endl;
        // 前面的都是加入了也不会产生作用的t里面没有的字母
        while(window.find(s[j])==window.end()&&j<s.size()){
            j++;
            cout<<i<<" "<<j<<" "<<matched<<endl;
        }
        // 这个加入是t里面需要的，j永远指向下一个要进行匹配的值
        window[s[j]]++;
        
        cout<<i<<" "<<j<<" "<<matched<<endl;
        // 如果加入了正好能满足一个字母的需求，匹配个数++
        if(window[s[j]]==um[s[j]]) {
            matched++;
        }
        j++;
        cout<<i<<" "<<j<<" "<<matched<<endl;
        // 如果满足匹配，就要考虑如何减少长度
        while(matched==match){
            // 先存一下
            if(minlen>j-i){
                minlen=j-i;
                pos=i;
                cout<<"min"<<i<<" "<<j<<" "<<matched<<endl;
            }
            if(window.find(s[i])!=window.end()){
                if(window[s[i]]==um[s[i]]){
                    matched--;
                }
                window[s[i]]--;
            }
            i++;
        }
    }
    return minlen==0x7FFFFFFF?"":s.substr(pos,minlen);
}
// 只要出现过一次就算匹配了
string minWindow(string s, string t) {
    unordered_map<char,int> window;
    for(auto c:t){
        window[c]=0;
    }
    int match=window.size(),matched=0;
    int i=0,j=0,minlen=0x7FFFFFFF,pos=0;
    while(i<=j&&j<s.size()){
        // 前面的都是加入了也不会产生作用的t里面没有的字母
        while(window.find(s[j])==window.end()&&j<s.size()){
            j++;
        }
        // 下面的j指的最后一个刚加入的位置
        // 这个加入是t里面需要的，j永远指向下一个要进行匹配的值
        window[s[j]]++;
        
        // 如果加入了正好能满足一个字母的需求，匹配个数++
        if(window[s[j]]==1) {
            
            matched++;
        }
        // 指向下一个
        j++;
        // 如果满足匹配，就要考虑如何减少长度
        while(matched==match){
            // 先存一下
            if(minlen>j-i){
                minlen=j-i;
                pos=i;
            }
            // 如果i位置是需要的字符，则需要进一步判断
            if(window.find(s[i])!=window.end()){
                if(window[s[i]]==1){
                    matched--;
                }
                window[s[i]]=max(--window[s[i]],0);
            }
            i++;
        }
    }
    return s.substr(pos,minlen);
}

int main(int argc, char const *argv[])
{
    string s{"a"};
    string t{"b"};
    cout<<minWindow_v0(s,t);
    return 0;
}
