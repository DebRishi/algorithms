#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void merge(long long arr1[],long long arr2[],int n1,int n2) {
            int i = n1-1;
            int j = 0;
            while(i >= 0 && j < n2) {
                if(arr1[i] > arr2[j])
                    swap(arr1[i--],arr2[j++]);
                else
                    break;
            }
            sort(arr1,arr1+n1);
            sort(arr2,arr2+n2);
        } 
};

int main() {
    int n1 = 6;
    int n2 = 4;
    long long arr1[] = {1,5,9,10,15,20};
    long long arr2[] = {2,3,8,13};

    Solution s;
    s.merge(arr1,arr2,n1,n2);
}