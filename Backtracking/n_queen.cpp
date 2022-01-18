#include<iostream>
#include<vector>
using namespace std;
#define vvs vector<vector<string>>
#define vs vector<string>

class Solution {
    public:

    bool isSafe(vs board,int n,int row,int col) {
        for(int j = col ; j >= 0 ; j--) {
            if(board[row][j] == 'Q') return false;
        }

        for(int i = row,j = col ; i >= 0 && j >= 0 ; i-- , j--) {
            if(board[i][j] == 'Q') return false;
        }

        for(int i = row,j = col ; i < n && j >= 0 ; i++ , j--) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    
    void solve(vvs & ans,vs board,int n,int col = 0) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++) {
            if(isSafe(board,n,row,col)) {
                board[row][col] = 'Q';
                solve(ans,board,n,col+1);
                board[row][col] = '.';
            }
        }
    }
    vvs nQueen(int n) {
        vvs ans;
        vs board;
        for(int i = 0 ; i < n ; i++) board.push_back(string(n,'.'));
        solve(ans,board,n);
        return ans;
    }
};

int main() {
    Solution s;
    for(auto board : s.nQueen(4)) {
        for(auto i : board) {
            cout<<i<<endl;
        }
        cout<<string(100,'-')<<endl;
    }
    return 0;
}