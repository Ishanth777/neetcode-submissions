class Solution {
public:
bool dfs(int idx,int row,int col,vector<vector<char>>&board,string &word,vector<vector<int>>&vis){
    if(idx == word.size())return true;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    for(int i=0;i<4;i++){
        int nr = dr[i] + row;
        int nc = dc[i] + col;

        if(nr >=0 && nc >=0 && nr < board.size() && nc < board[0].size() && !vis[nr][nc] && board[nr][nc] == word[idx]){
            vis[nr][nc] = 1;
            if(dfs(idx+1,nr,nc,board,word,vis))return true;
            vis[nr][nc] = 0;
        }
    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                vector<vector<int>>vis(m,vector<int>(n));
                if(board[r][c] == word[0]){
                    vis[r][c] = 1;
                    if(dfs(1,r,c,board,word,vis))return true;
                }
            }
        }
        return false;
    }
};
