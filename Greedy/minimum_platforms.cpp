#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int plat = 1;
        int ans = 1;
        int i = 1;
        int j = 0;
        while(i < n) {
            if(arr[i] <= dep[j]) {
                plat++;
                i++;
            }
            else {
                plat--;
                j++;
            }
            ans = max(ans,plat);
        }
        return ans;
    }
};

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    Solution s;
    cout<<s.findPlatform(arr,dep,n);
    return 0;
}