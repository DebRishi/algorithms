#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<char>> & board,string word,int i,int j,int index) {
    if(index == word.length()) {
        return true;
    }
    if(i == -1 || i == board.size() || j == -1 || j == board[0].size() || board[i][j] != word[index]) {
        return false;
    }
    char temp = board[i][j];
    board[i][j] = '*';
    bool t = check(board,word,i-1,j,index+1);
    bool l = check(board,word,i,j-1,index+1);
    bool r = check(board,word,i,j+1,index+1);
    bool b = check(board,word,i+1,j,index+1);
    board[i][j] = temp;
    return (t || l || r || b);
}

bool wordSearch(vector<vector<char>> & board,string word) {
    for(int i = 0 ; i < board.size() ; i++) {
        for(int j = 0 ; j < board[0].size() ; j++) {
            if(board[i][j] == word[0] && check(board,word,i,j,0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout<<wordSearch(board,word)<<endl;
    return 0;
}