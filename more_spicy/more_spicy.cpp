#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0;i<scoville.size();i++){
        minHeap.push(scoville[i]);
    }
    
    int answer=0;
    while(minHeap.top()<K){
        answer++;
        int first=minHeap.top();
        minHeap.pop();
        if(minHeap.empty()){
            answer=-1;
            break;
        }
        int second=minHeap.top();
        minHeap.pop();
        
        int new_food=first+2*second;
        minHeap.push(new_food);
    }
    
    return answer;
}