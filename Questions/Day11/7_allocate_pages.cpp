#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<int> pages,int studs,int max) {
    int n = 1;
    int sum = 0;
    for(int p : pages) {
        sum += p;
        if(sum > max) {
            n++;
            sum = p;
        }
    }
    if(n > studs)
        return false;
    return true;
}

int allocatePages(vector<int> pages,int studs) {
    int min = pages[0];
    int sum = 0;
    for(auto p : pages) {
        min = std::min(min,p);
        sum += p;
    }
    int low = min;
    int hii = sum;
    int ans = -1;
    while(low <= hii) {
        int mid = low + (hii - low)/2;
        if(isSafe(pages,studs,mid)) {
            ans = mid;
            hii = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int main() {
    vector<int> pages = {12,34,67,90};
    int studs = 2;
    cout<<allocatePages(pages,studs);
}