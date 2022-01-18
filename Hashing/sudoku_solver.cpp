#include <iostream>
#include <vector>
#include <map>
using namespace std;

map <pair <int,int>,map <int,int>> section;
vector <map <int,int>> row(9);
vector <map <int,int>> col(9);
vector <vector <char>> ans;

void helper(vector <vector <char>> & board,int r = 0,int c = 0) {
    if(r == 9) {
        for(int i = 0 ; i < 9 ; i++) {
            vector <char> temp;
            for(int j = 0 ; j < 9 ; j++) {
                temp.push_back(board[i][j]);
            }
            ans.push_back(temp);
        }
        return;
    }
    if(c == 9) {
        helper(board,r+1,0);
        return;
    }
    if(board[r][c] != '.') {
        helper(board,r,c+1);
        return;
    }
    for(int i = 1 ; i <= 9 ; i++) {
        if(!section[{r/3,c/3}][i] and !row[r][i] and !col[c][i]) {
            section[{r/3,c/3}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            board[r][c] = i + '0';
            helper(board,r,c+1);
            section[{r/3,c/3}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            board[r][c] = '.';
        }
    }
}

void sudokuSolver(vector <vector <char>> & board) {
    for(int i = 0 ; i < 9 ; i++) {
        for(int j = 0 ; j < 9 ; j++) {
            if(board[i][j] != '.') {
                section[{i/3,j/3}][board[i][j]-'0'] = 1;
                row[i][board[i][j]-'0'] = 1;
                col[j][board[i][j]-'0'] = 1;
            }
        }
    }
    helper(board);
}

int main() {
    vector <vector <char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sudokuSolver(board);
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}