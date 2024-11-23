class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }

        int min=0;
        while(!q.empty()){
            vector<pair<int,int>> rotten_oranges;
            while(!q.empty()){
                pair<int,int> rotten_orange=q.front(); q.pop();
                rotten_oranges.push_back(rotten_orange);
            }
            for(int i=0;i<rotten_oranges.size();i++){
                pair<int,int>rotten_orange=rotten_oranges[i];
                int x=rotten_orange.first;
                int y=rotten_orange.second;

                if(x+1<m && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push(make_pair(x+1,y));
                }
                if(y+1<n && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push(make_pair(x,y+1));
                }
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push(make_pair(x-1,y));
                }
                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push(make_pair(x,y-1));
                }
            }
            min++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return min>0 ? min-1 : 0;
    }
};