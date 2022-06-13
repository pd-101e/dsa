class Solution {
public:
    
     vector<vector<string>> res;
     bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &board ,int row,int n )
    {
        if(row == n)
        {
            res.push_back(board);
            return ;
        }
        for(int i = 0 ; i<n ; i++)
        {
            if(is_valid(board,row,i))
            {
                
                board[row][i] = 'Q';
                dfs(board,row+1,n);
                board[row][i] = '.';
               
            }
        }
        return ;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
       if (n<=0) return {{}};
        
        vector<string>board(n,string(n,'.'));
        
       
        dfs(board,0,n);
        
        return res;
        
    }
};


//----------------------------------------------------------------------------------------------------------------------------------------------------
class Solution{
public:

vector<vector<int>>res;

bool isvalid(vector<vector<int>>board , int row , int col)
{
    for(int i = col ; i>=0 ; i--)
    {
        if(board[row][i]) return false;
    }
    
    for(int i = row , j= col ; i>=0 and j>=0 ; i-- , j--)
    if(board[i][j]) return false;
    
    for(int i = row , j= col ; j>=0 and i<board.size() ; i++, j--)
    if(board[i][j]) return false;
    
    return true;
    
}

void dfs(vector<vector<int>>&board , int col , int n)
{
    if(col == n)
    {
        vector<int>temp;
        
        for(int i =0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(board[i][j] == 1)
                {
                    temp.push_back(j + 1);
                }
            }
        }
        res.push_back(temp);
        return;
    }
    
    for(int i = 0 ; i<n ; i++ )
    {
        if(isvalid(board , i , col))
        {
            board[i][col] = 1;
            dfs(board , col + 1 , n);
            board[i][col] = 0;
        }
    }
    return;
    
}

    vector<vector<int>> nQueen(int n) {
        // code here
        
        if(n <= 0)
        return {{}};
        
        vector<vector<int>>board(n , vector<int>(n, 0));
        
        dfs(board,0,n);
        sort(res.begin() , res.end());
        return res;
        
    }
};
