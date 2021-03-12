class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void BFS(int row,int col,int n,int m,vector<vector<char>>& board,vector<vector<int>> &vis){
        if(row < 0 || col < 0 || row >=n || col>=m || vis[row][col] || board[row][col]== 'X')
            return;
        
        vis[row][col] = 1;
        
        for(int i=0;i<4;i++)
            BFS(row+dx[i],col+dy[i],n,m,board,vis);
    }
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m= board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') BFS(0,i,n,m,board,vis);
            if(board[n-1][i]=='O' ) BFS(n-1,i,n,m,board,vis);
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') BFS(i,0,n,m,board,vis);
            if(board[i][m-1]=='O' ) BFS(i,m-1,n,m,board,vis);
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j]) board[i][j] = 'X';
    }
};