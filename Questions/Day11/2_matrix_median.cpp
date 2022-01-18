#include<iostream>
#include<vector>
using namespace std;

class Solution{   
public:
    int countLesser(vector<vector<int>>& matrix,int num) {
        int count = 0;
        for(auto arr : matrix) {
            int i = 0;
            int j = arr.size();
            while(i < j) {
                int mid = i + (j-i)/2;
                if(arr[mid] <= num)
                    i = mid+1;
                else
                    j = mid;
            }
            count += i;
        }
        return count;
    }

    int findMedian(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int min = matrix[0][0];
        int max = matrix[0][0];
        for(auto i : matrix) {
            for(auto j : i) {
                min = std::min(min,j);
                max = std::max(max,j);
            }
        }
        int req = (r*c+1)/2;
        while(min < max) {
            int mid = min + (max-min)/2;
            if(countLesser(matrix,mid) < req)
                min = mid+1;
            else
                max = mid;
        }
        return min;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    Solution s;
    cout<<s.findMedian(matrix);
}