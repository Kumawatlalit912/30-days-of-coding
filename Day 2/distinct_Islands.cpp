class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,
    vector<pair<int,int>>&v,int base_row,int base_col,int dx[],int dy[],int n,
    int m){
        vis[i][j]=1;
        v.push_back({i-base_row,j-base_col});
        for(int k=0;k<4;k++){
            int dr=i+dx[k];
            int dc=j+dy[k];
            if(dr>=0 && dr<n && dc>=0 && dc<m && !vis[dr][dc]
            && grid[dr][dc]==1){
                dfs(dr,dc,grid,vis,v,base_row,base_col,dx,dy,n,m);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,vis,v,i,j,dx,dy,n,m);
                    
                    s.insert(v);
                }
            }
        }
        return s.size();
        
    }
