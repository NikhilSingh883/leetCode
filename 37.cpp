class Solution {
public:
    
    bool check(int num,int row,int col,vector<vector<char>> b){
        for(int i=0;i<9;i++)
            if(b[row][i] ==('0'+num)) return false;
        
        for(int i=0;i<9;i++)
            if(b[i][col] == ('0'+num)) return false;
        
        int r =row- row%3;
        int c =col- col%3;
        
        for(int i=r;i<r+3;i++)
            for(int j=c;j<c+3;j++)
                if(b[i][j]==('0'+num)) return false;
        
        return true;
    }
    
    bool findEmpty(int &row, int &col, vector<vector<char> > &A){
        for(row=0;row<A.size();row++){
            for(col=0;col<A[row].size();col++){
                if(A[row][col]=='.')
                return true;
            }
        }
        return false;
    }
    
    bool solve(vector<vector<char>>& b){
        
        int row,col;
        if(!findEmpty(row,col,b))
            return true;
        
        for(int num=1;num<=9;num++){
            if(check(num,row,col,b)){
                b[row][col] = num +'0';
                if(solve(b))
                    return true;
                b[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board);
    }
};