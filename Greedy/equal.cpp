#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int equal(vector<int> arr) {
    vector<int> steps(5,0);
    int minInt = *min_element(arr.begin(),arr.end());
    for(int i = 0 ; i < 5 ; i++) {
        for(int x : arr) {
            int diff = x - minInt;
            int count = diff/5 + (diff%5)/2 + ((diff%5)%2)/1;
            steps[i] += count;
        }
        minInt--;
    }
    return *min_element(steps.begin(),steps.end());
}

int main() {
    vector<int> arr = {2,2,3,7};
    cout<<equal(arr)<<endl;
    return 0;
}