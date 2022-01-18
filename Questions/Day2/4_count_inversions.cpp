#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    public:
    int ans;

    void merge(vector<int> & arr,int start,int mid,int end) {
        vector<int> temp;
        int i = start;
        int j = mid+1;
        while(i <= mid && j <= end) {
            if(arr[j] < arr[i]) {
                temp.push_back(arr[j++]);
                ans += mid-i+1;
            }
            else {
                temp.push_back(arr[i++]);
            }
        }
        while(i <= mid) {
            temp.push_back(arr[i++]);
        }
        while(j <= end) {
            temp.push_back(arr[j++]);
        }
        for(int k = 0 ; k < temp.size() ; k++) {
            arr[start+k] = temp[k];
        }
    }

    void mergeSort(vector<int> & arr,int start,int end) {
        if(start < end) {
            int mid = start + (end-start)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }

    int inversionCount(vector<int> arr) {
        ans = 0;
        mergeSort(arr,0,arr.size()-1);
        return ans;
    }
};

// USING MULTISET
// class Solution{
//   public:

//     int inversionCount(vector<int> & nums) {
//         int ans = 0;
//         multiset<int> set;
//         for(int i : nums) {
//             set.insert(i);
//             ans += distance(set.upper_bound(i),set.end());
//         }
//         return ans;
//     }
// };

int main() {
    vector<int> arr = {1,20,6,7,5,8,11,3};
    Solution s;
    cout<<s.inversionCount(arr)<<endl;
    return 0;
}

