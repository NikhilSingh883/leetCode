class Solution {
public:
    
    int dx[4] ={-1,1,0,0};
    int dy[4] ={0,0,-1,1};
    
    bool find(int row,int col,int idx,int n,int m,vector<vector<int>>& vis,vector<vector<char>>& b,string word){
        if(idx == word.size())
            return true;
        
        if(row <0 || col <0 || row >=n || col >=m || vis[row][col] || b[row][col]!=word[idx])
            return false;
        
        vis[row][col] = true;
        
        for(int i=0;i<4;i++)
            if(find(row+dx[i],col+dy[i],idx+1,n,m,vis,b,word))
                return true;
        
        vis[row][col] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    if(find(i,j,0,n,m,vis,board,word))
                        return true;
        return false;
    }
};