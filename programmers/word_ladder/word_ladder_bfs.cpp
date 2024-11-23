#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

bool checkF(string begin, string word){
    int diff=0;
    for(int i=0;i<begin.size();i++){
        if(begin[i]!=word[i]){
            diff++;
            if(diff>1){
                return false;
            }
        }
    }
    if(diff==1){
        return true;
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    stack<pair<int, string>> S;
    vector<bool> visited(words.size(), false);
    
    for(int i=0;i<words.size();i++){
        string word=words[i];
        if(checkF(begin, word)){
            visited[i]=true;
            S.push(make_pair(1,word));
        }
    }
    
    int return_value=-1;
    while(!S.empty()){
        pair<int,string> word_info = S.top();
        S.pop();
        int time=word_info.first;
        string begin=word_info.second;
        
        if(begin==target){
            if(return_value==-1||time<return_value){
                return_value=time;
            }
        }
        for(int i=0;i<words.size();i++){
            if(visited[i]){
                continue;
            }
            string word=words[i];
            if(!checkF(begin, word)){
                continue;
            }
            visited[i]=true;
            S.push(make_pair(time+1,word));
        }
    }
    if(return_value==-1){
        return 0;
    }
    return return_value;
}