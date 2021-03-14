#include<vector>
#include<iostream>
#include<queue>
#include<list>

using namespace std;
// 使用DFS超时，因为要搜索最短的路径，深搜需要搜索所有情况，无法有效的根据层剪枝
bool canturn(string s,string t){
    int len = s.length();
    int dis = 0;
    for(int i=0;i<len;i++){
        if(s[i]!=t[i]){
            dis++;
        }
    }
    return dis==1;
}

void backTrack(int n,string &currentStr,string &endStr, vector<string>& wordList,vector<bool> &used,vector<string> &track,vector<vector<string>> &out){
    if(currentStr == endStr){
        // track.emplace_back(endStr);
        // 如果记录的比我自己的路径长，就清空out
        if(out.size()>0&&out[0].size()>track.size()){
                out.clear();
        }
        if(out.size()==0||out[0].size()==track.size()){
            out.push_back(track);
        }
    }else{
        for(int i=0;i<n;i++){
            if(used[i]||!canturn(currentStr,wordList[i])) continue;
            used[i] = true;
            track.emplace_back(wordList[i]);
            backTrack(n,wordList[i],endStr,wordList,used,track,out);
            used[i] = false;
            track.pop_back();
        }
    }
}
vector<vector<string>> findLadders_v1(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> out;
    int n_wl = wordList.size();
    vector<bool> used(n_wl,false);
    vector<string> track{beginWord};
    backTrack(n_wl,beginWord,endWord,wordList,used,track,out);
    return out;
}

// BFS
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> out;
    int n_wl = wordList.size();
    wordList.push_back(beginWord);
    vector<bool> used(n_wl,false);

    // find end idx
    int endidx=-1;
    for(int i=0;i<n_wl;i++){
        if(wordList[i]==endWord){
            endidx = i;
            break;
        }
    }
    if(endidx==-1) return out;

    vector<int> before(n_wl,-1);
    list<string> track;
    queue<int> queStr;
    queStr.push(n_wl);
    while(!queStr.empty()){
        int tmp = queStr.front();
        queStr.pop();
        if(tmp==endidx){
            while(before[tmp]!=-1){
                track.push_front(wordList[tmp]);
                tmp = before[tmp];
            }
            if(out.size()>0&&out[0].size()<track.size()) return out;
            out.push_back(vector<string>(track.begin(),track.end()));
            track.clear();
        }
        for(int i=0;i<n_wl;i++){
            if(used[i]||!canturn(wordList[tmp],wordList[i])) continue;
            used[i] = true;
            before[i] = tmp;
            queStr.push(i);
        }
    }

    return out;
}

int main(){
    string star = "hit";
    string end = "cog";
    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
    findLadders(star,end,wl);
}