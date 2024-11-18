#include <string>
#include <vector>

using namespace std;

int calculateScoreDiff(vector<int>& lion, vector<int>& apach){
    int score_diff=0;
    for(int i=0;i<=10;i++){
        if(lion[i]>apach[i]){
            score_diff+=(10-i);
        }else if(lion[i]<apach[i]){
            score_diff-=(10-i);
        }else{
            if(!(lion[i]==0&&apach[i]==0)){
                score_diff-=(10-i);
            }
        }
    }
    return score_diff;
}

bool iscase1Better(vector<int>& case1, vector<int>& case2){
    for(int i=10;i>=0;i--){
        if(case1[i]>case2[i]){
            return true;
        }else if(case1[i]<case2[i]){
            return false;
        }
    }
    return false;
}

vector<int> best_lion;
int best_score_diff=-56;

void DFS(int idx, vector<int> lion, vector<int>& apach, int remain){
    if(idx==10){
        lion[idx]=remain;
        int score_diff=calculateScoreDiff(lion,apach);
        if(score_diff>0){
            if(score_diff>best_score_diff){
                best_lion=lion;
                best_score_diff=score_diff;
            }else if(score_diff==best_score_diff){
                if(iscase1Better(lion,best_lion)){
                    best_lion=lion;
                }
            }
        }
        return;
    }
    
    for(int i=0;i<=remain;i++){
        vector<int>next_lion=lion;
        next_lion[idx]=i;
        DFS(idx+1,next_lion,apach,remain-i);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> init_lion(11,0);
    DFS(0,init_lion,info,n);
    if(best_score_diff<=0){
        return vector<int>{-1};
    }
    return best_lion;
}