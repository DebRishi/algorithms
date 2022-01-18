#include<iostream>
#include<vector>
using namespace std;

// LEETCODE PART 1
class Solution {
public:
    
    bool search(vector<int> arr,int key) {
        int low = 0;
        int high = arr.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == key) return true;
            else if(arr[mid] < key) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        int n = matrix.size();
        int i = 1;
        while(i < n) {
            if(matrix[i][0] > key) break;
            i++;
        }
        return search(matrix[i-1],key);
    }
};

// LEETCODE PART 2
// class Solution {
// public:
    
//     bool search(vector<int>& arr,int key) {
//         int low = 0;
//         int high = arr.size()-1;
//         while(low <= high) {
//             int mid = low + (high-low)/2;
//             if(arr[mid] == key) return true;
//             else if(arr[mid] < key) low = mid+1;
//             else high = mid-1;
//         }
//         return false;
//     }
    
//     bool searchMatrix(vector<vector<int>>& matrix, int key) {
//         int r = matrix.size();
//         int c = matrix[0].size();
//         int i = 0;
//         while(i < r) {
//             if(matrix[i][0] <= key && key <= matrix[i][c-1] && search(matrix[i],key)) {
//                 return true;
//             }
//             i++;
//         }
//         return false;
//     }
// };

int main() {
    // part 1
    vector<vector<int>> matrix = {
        { 1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,50}
    };
    int key = 11;

    // part 2
    // vector<vector<int>> matrix = {
    //     { 1, 4, 7,11,15},
    //     { 2, 5, 8,12,19},
    //     { 3, 6, 9,16,22},
    //     {10,13,14,17,24},
    //     {18,21,23,26,30}
    // };
    // int key = 5;

    Solution s;
    cout<<s.searchMatrix(matrix,key)<<endl;
    return 0;
}