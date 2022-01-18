#include <iostream>
#include <vector>
using namespace std;

void transpose(vector <vector <int>> & matrix) {
    for(int r = 0 ; r < matrix.size() ; r++) {
        for(int c = r+1 ; c < matrix.size() ; c++) {
            swap(matrix[r][c],matrix[c][r]);
        }
    }
}

void turn(vector <vector <int>> & matrix) {
    for(int r = 0 ; r < matrix.size() ; r++) {
        int i = 0;
        int j = matrix.size()-1;
        while(i < j) {
            swap(matrix[r][i],matrix[r][j]);
            i++;
            j--;
        }
    }
}

void rotate(vector <vector <int>> & matrix) {
    transpose(matrix);
    turn(matrix);
}

// 1. Get Transpose
// 2. Switch Horizontaly

// [1,2,3]      [1,4,7]      [7,4,1]
// [4,5,6]  ->  [2,5,8]  ->  [8,5,2]
// [7,8,9]      [3,6,9]      [9,6,3]

int main() {
    vector <vector <int>> matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    rotate(matrix);
    for(auto i : matrix) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}