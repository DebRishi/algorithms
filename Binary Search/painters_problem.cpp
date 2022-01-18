#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector <int> b,int p,int limit) {
    int count = 1;
    int sum = 0;
    for(auto i : b) {
        if(sum + i > limit) {
            count++;
            sum = i;
        }
        else {
            sum += i;
        }
    }
    if(count <= p) {
        return true;
    }
    else {
        return false;
    }
}

int minimumTime(vector <int> boards,int painters) {
    if(painters > boards.size()) {
        return -1;
    }
    int sum = 0;
    int max = INT_MIN;
    for(auto i : boards) {
        sum += i;
        max = std::max(max,i);
    }
    int start = max;
    int end = sum;
    int ans = -1;
    while(start < end) {
        int mid = start + (end-start)/2;
        if(isPossible(boards,painters,mid)) {
            ans = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return ans;
}

int main() {
    cout<<minimumTime({10,20,30,40},2);
    return 0;
}