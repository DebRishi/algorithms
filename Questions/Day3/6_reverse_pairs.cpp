#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int pairs;
    
    void merge(vector<long long>& arr,int start,int mid,int end) {
        vector<long long> temp;
        int i = start;
        int j = mid+1;
        while(i <= mid && j <= end) {
            if(arr[i] < arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
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
    
    void countPairs(vector<long long>& arr,int start,int mid,int end) {
        int j = mid+1;
        for(int i = start ; i <= mid ; i++) {
            while(j <= end && arr[i] > 2*arr[j]) {
                j++;
            }
            pairs += j-mid-1;
        }
    }
    
    void mergeSort(vector<long long>& arr,int start,int end) {
        if(start < end) {
            int mid = start + (end-start)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            countPairs(arr,start,mid,end);
            merge(arr,start,mid,end);
        }
    } 
    
    int reversePairs(vector<int>& nums) {
        pairs = 0;
        vector<long long> arr(nums.begin(),nums.end());
        mergeSort(arr,0,arr.size()-1);
        return pairs;
    }
};

int main() {
    vector<int> nums = {1,3,2,3,1};
    Solution s;
    cout<<s.reversePairs(nums);
    return 0;
}