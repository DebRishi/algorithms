#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<int> stalls,int gap,int n) {
    int left = stalls[0];
    for(int i = 1 ; i < stalls.size() ; i++) {
        if(stalls[i]-left >= gap) {
            n--;
            left = stalls[i];
        }
    }
    return n <= 0;
}

int aggressiveCows(vector<int> stalls,int cows) {
    int n = stalls.size();
    int ans = -1;
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    while(low <= high) {
        int gap = low + (high-low)/2;
        if(isSafe(stalls,gap,cows-1)) {
            ans = gap;
            low = gap+1;
        }
        else
            high = gap-1;
    }
    return ans;
}

int main() {
    vector<int> stalls = {1,2,4,8,9,12,16};
    int cows = 4;
    cout<<aggressiveCows(stalls,cows);
    return 0;
}