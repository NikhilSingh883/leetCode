class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void BFS(int row,int col,int n,int m,vector<vector<char>>& board,vector<vector<int>> &vis){
        if(row < 0 || col < 0 || row >=n || col>=m || vis[row][col] || board[row][col]== '0')
            return;
        
        vis[row][col] = 1;
        
        for(int i=0;i<4;i++)
            BFS(row+dx[i],col+dy[i],n,m,board,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans =0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && grid[i][j] == '1'){
                    BFS(i,j,n,m,grid,vis);
                    ans++;
                }
        
        return ans;
    }
};