#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
bool isSubstr(string s,string t){
    int i=0,j=0;
    while(i<s.size()&&j<t.size()){
        if(s[i]==t[j]){
            j++;
        }
        i++;
    }
    return j==t.size();
}
string minStr(string a,string b){
    if(a.size()>b.size()){
        return a;
    }else if (a.size()<b.size())
    {
        return b;
    }else{
        return a<b?a:b;
    }
}
// 88 ms 24.7 MB
string findLongestWord_v1(string s, vector<string>& dictionary) {
    string out{""};
    for(auto vs:dictionary){
        if(isSubstr(s,vs)){
            out = minStr(out,vs);
        }
    }
    return out;
}
// 68 ms 24.7 MB
string findLongestWord_v2(string s, vector<string>& dictionary) {
    string out{""};
    for(auto vs:dictionary){
        // 筛选到不可能匹配的值
        if(vs.size()<=s.size()&&isSubstr(s,vs)){
            out = minStr(out,vs);
        }
    }
    return out;
}
// 以为多判断就好的。。
// 72 ms 24.7 MB
string findLongestWord_v3(string s, vector<string>& dictionary) {
    string out{""};
    int flag = s.size();
    for(auto vs:dictionary){
        // 筛选到不可能匹配的值
        if(vs.size()<=flag&&isSubstr(s,vs)){
            out = minStr(out,vs);
            flag = flag<vs.size()?vs.size():flag;
        }
    }
    return out;
}

static bool minComp(string a,string b){
    if(a.size()>b.size()){
        return false;
    }else if (a.size()<b.size())
    {
        return true;
    }else{
        return a<b?false:true;
    }
}
// 先排序的话代价更大了
// 124 ms 79.9 MB 
string findLongestWord(string s, vector<string>& dictionary) {
    sort(dictionary.begin(),dictionary.end(),minComp);
    int ei = dictionary.size()-1;
    while(ei>=0){
        if(dictionary[ei].size()<=s.size()&&isSubstr(s,dictionary[ei])){
            return dictionary[ei];
        }
        ei--;
    }
    return "";
}
int main(int argc, char const *argv[])
{
    vector<string> dictionary{"ale","apple","monkey","plea", "abpcplaaa","abpcllllll","abccclllpppeeaaaa"};
    cout<<findLongestWord("abpcplea",dictionary);
    return 0;
}
