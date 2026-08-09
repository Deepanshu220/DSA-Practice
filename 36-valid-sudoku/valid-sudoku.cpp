class Solution {
public:
    bool valid(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        unordered_set<int> st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()) return false;
                st.insert(board[i][j]); 
            }
        }
        return true;       
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //Optimal Force Method
        unordered_set<string> st;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                string row=string(1,board[r][c])+"ROW"+to_string(r);
                string col=string(1,board[r][c])+"COL"+to_string(c);
                string box=string(1,board[r][c])+"BOX"+to_string(r/3)+"_"+to_string(c/3);

                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};