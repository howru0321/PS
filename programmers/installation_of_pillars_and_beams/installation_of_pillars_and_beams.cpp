#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> wall_pillars;
vector<vector<int>> wall_beams;
int N;


void addPillar(int x, int y){
    if(
        (y==0)
        ||
        (wall_beams[x][y]==1 || (x>=1 && wall_beams[x-1][y]==1))
        ||
        (y>=1 && wall_pillars[x][y-1]==1)
      ){
        wall_pillars[x][y]=1;
    }
}
void addBeam(int x, int y){
    if(
        (wall_pillars[x][y-1]==1 || (x<N && wall_pillars[x+1][y-1]==1))
        ||
        ((x>=1 && wall_beams[x-1][y]==1) && (x<N && wall_beams[x+1][y]==1))
    ){
        wall_beams[x][y]=1;
    }
}

bool checkValid(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(wall_pillars[i][j]==1){
                if(
                    !(
                        (j==0)
                        ||
                        (wall_beams[i][j]==1 || (i>=1 && wall_beams[i-1][j]==1))
                        ||
                        (j>=1 && wall_pillars[i][j-1]==1)
                    )
                  ){
                    return false;
                }
            }
            if(wall_beams[i][j]==1){
                if(
                    !(
                        (wall_pillars[i][j-1]==1 || (i<N && wall_pillars[i+1][j-1]==1))
                        ||
                        ((i>=1 && wall_beams[i-1][j]==1) && (i<N && wall_beams[i+1][j]==1))
                    )
                ){
                    return false;
                }
            }
        }
    }
    return true;
}

void removePillar(int x, int y){
    if(wall_pillars[x][y]==0){
        return;
    }
    wall_pillars[x][y]=0;
    if(!checkValid()){
        wall_pillars[x][y]=1;
    }
}
void removeBeam(int x, int y){
    if(wall_beams[x][y]==0){
        return;
    }
    wall_beams[x][y]=0;
    if(!checkValid()){
        wall_beams[x][y]=1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N=n;
    wall_pillars.resize(n+1);
    wall_beams.resize(n+1);
    for(int i=0;i<=n;i++){
        wall_pillars[i].resize(n+1,0);
        wall_beams[i].resize(n+1,0);
    }
    
    
    for(int i=0;i<build_frame.size();i++){
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        int a=build_frame[i][2];
        int b=build_frame[i][3];
        
        if(a==0){
            if(b==1){
                addPillar(x,y);
            }else if(b==0){
                removePillar(x,y);
            }
        }else if(a==1){
            if(b==1){
                addBeam(x,y);
            }else if(b==0){
                removeBeam(x,y);
            }
        }
    }
    
    vector<vector<int>> answer;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(wall_pillars[i][j]==1){
                vector<int> pillar = {i,j,0};
                answer.push_back(pillar);
            }
            if(wall_beams[i][j]==1){
                vector<int> beam = {i,j,1};
                answer.push_back(beam);
            }
        }
    }
    return answer;
}