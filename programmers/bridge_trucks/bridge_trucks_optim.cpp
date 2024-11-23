#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> bridge;
    
    int total_weight=0;
    int idx=0;
    while(idx<truck_weights.size() || !bridge.empty()){
        if(!bridge.empty() && bridge.front().second==answer){
            total_weight-=bridge.front().first;
            bridge.pop();
        }
        
        if(idx<truck_weights.size() && (weight-total_weight)>=truck_weights[idx]){
            bridge.push(make_pair(truck_weights[idx], answer+bridge_length));
            total_weight+=truck_weights[idx];
            idx++;
            answer++;
        }else if(!bridge.empty()){
            answer=bridge.front().second;
        }
    }
    return answer+1;
}