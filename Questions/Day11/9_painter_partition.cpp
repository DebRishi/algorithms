#include<iostream>
#include<vector>
using namespace std;

int isFeasible(vector<int> boards,int limit) {
    int sum = 0;
    int paints = 1;
    for(int b : boards) {
        sum += b;
        if(sum > limit) {
            paints++;
            sum = b;
        }
    }
    return paints;
}

int paintersPartition(vector<int> boards,int paints) {
    int max = boards[0];
    int sum = 0;
    for(int b : boards) {
        max = std::max(max,b);
        sum += b;
    }
    int ans = -1;
    int low = max;
    int hii = sum;
    while(low <= hii) {
        int mid = low + (hii - low)/2;
        if(isFeasible(boards,mid) <= paints) {
            ans = mid;
            hii = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int main() {
    vector<int> boards = {10,20,30,40};
    int paints = 2;
    cout<<paintersPartition(boards,paints);
}