#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    set <int> row;
    set <int> col;
    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++) {
            if(matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    
    for(auto i : row) {
        for(int j = 0 ; j < c ; j++) {
            matrix[i][j] = 0;
        }
    }
    
    for(auto j : col) {
        for(int i = 0 ; i < r ; i++) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    vector <vector <int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for(auto i : matrix) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}