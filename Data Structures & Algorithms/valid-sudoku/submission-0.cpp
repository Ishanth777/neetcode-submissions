class Solution {
public:
bool help(int row,int col,vector<vector<char>>&board,char &c){
    for(int i=0;i<9;i++){
        if(board[i][col]==c)return false;
        if(board[row][i]==c)return false;

        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)return false;
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char c = board[i][j];
                    board[i][j] = '.';
                    if(!help(i,j,board,c))return false;
                }
            }
        }
        return true;
    }
};
