class Solution {
    private:
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int r=row+i;
                    int c=col+j;
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1'&&!vis[r][c]){
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
            
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
