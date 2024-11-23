#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int DFS(int time,string begin, string target, vector<string> words){
    int return_value = INT_MAX;
    for(int i=0;i<words.size(); i++){
        string word = words[i];
        int begin_diff_num=0;
        bool success=false;
        for(int j=0;j<begin.size();j++){
            if(begin[j]!=word[j]){
                begin_diff_num++;
                if(begin_diff_num>1){
                    success=false;
                    break;
                }
                success=true;
            }
        }
        if(!success){
            continue;
        }
        if(word==target){
            return time+1;
        }
        vector<string> next_words = words;
        next_words.erase(next_words.begin()+i);
        int value = DFS(time+1, word, target, next_words);
        if(value < return_value){
            return_value=value;
        }
    }
    if(return_value==INT_MAX){
        return 0;
    }
    return return_value;
}

int solution(string begin, string target, vector<string> words) {
    return DFS(0, begin, target, words);
}