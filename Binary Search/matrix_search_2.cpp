#include<bits/stdc++.h>
using namespace std;

// LEETCODE 240 - Search a 2D Matrix II
class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix,int row,int key) {
        int low = 0;
        int mid = 0;
        int hii = matrix[row].size()-1;
        while(low < hii) {
            mid = low + ((hii-low) >> 1);
            if(matrix[row][mid] < key)
                low = mid+1;
            else
                hii = mid;
        }
        return matrix[row][low] == key;
    }
    
    int lowerBound(vector<vector<int>>& matrix,int col,int key) {
        int low = 0;
        int mid = 0;
        int hii = matrix.size();
        while(low < hii) {
            mid = low + ((hii-low) >> 1);
            if(matrix[mid][col] < key)
                low = mid+1;
            else
                hii = mid;
        }
        return low;
    }
    
    int upperBound(vector<vector<int>>& matrix,int col,int key) {
        int low = 0;
        int mid = 0;
        int hii = matrix.size();
        while(low < hii) {
            mid = low + ((hii-low) >> 1);
            if(matrix[mid][col] <= key)
                low = mid+1;
            else
                hii = mid;
        }
        return low;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix,int key) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = lowerBound(matrix,cols-1,key);
        int upp = upperBound(matrix,0,key);
        for(int i = low ; i < upp ; i++) {
            if(binarySearch(matrix,i,key))
                return true;
        }
        return false;
    }
};