#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    for(int i=0;i<bridge_length;i++){
        bridge.push(0);
    }
    
    int total_weight=0;
    for(int i=0;i<truck_weights.size();i++){
        int truck_weight = truck_weights[i];
        while(true){
            answer++;
            int evict_truck_weight=bridge.front();
            bridge.pop();
            total_weight-=evict_truck_weight;
            if((weight-total_weight)>=truck_weight){
                bridge.push(truck_weight);
                total_weight+=truck_weight;
                break;
            }
            bridge.push(0);
        }
    }
    while(total_weight!=0){
        answer++;
        int evict_truck_weight=bridge.front();
        bridge.pop();
        total_weight-=evict_truck_weight;
    }
    return answer;
}