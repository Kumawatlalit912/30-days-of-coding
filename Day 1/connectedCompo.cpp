author::Kumawat_lalit

class Solution {
    private:
    void dfs(int src,vector<int>graph[],vector<int>&vis){
        vis[src]=1;
        for(auto child:graph[src]){
            if(!vis[child]){
                vis[child]=1;
                dfs(child,graph,vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>graph[V];
        vector<int>vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
            
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                count++;
            }
        }
        return count;
        
      
    }
};
