#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFeasible(vector <int> arr,int k,int mid) {
    int count = 1;
    int pos = arr[0];
    for(int i = 1 ; i < arr.size() ; i++) {
        if(arr[i] - pos >= mid) {
            pos = arr[i];
            count++;
            if(count == k) {
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(vector <int> arr,int k) {
    sort(arr.begin(),arr.end());
    int result = -1;
    int left = 1;
    int right = arr[arr.size()-1] - arr[0];
    while(left < right) {
        int mid = (left + right)/2;
        if(isFeasible(arr,k,mid)) {
            result = max(result,mid);
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return result;
}

int main() {
    vector <int> v = {1, 2, 8, 4, 9};
    cout<<largestMinDist(v,3);
    return 0;
}