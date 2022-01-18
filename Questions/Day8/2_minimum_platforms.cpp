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
    return 0;
}