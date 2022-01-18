#include <iostream>
#include <vector>
#include <map>
using namespace std;


int subArrayWithSumZero(vector <int> & v) {
    map <int,int> count;
    int prefixSum = 0;
    for(int i = 0 ; i < v.size() ; i++) {
        prefixSum += v[i];
        v[i] = prefixSum;
        count[prefixSum]++;
    }
    int ans = 0;
    for(auto i : count) {
        int c = i.second;
        ans += (c*(c-1))/2;
        if(i.first == 0) {
            ans += i.second;
        }
    }
    return ans;
}

int main() {
    vector <int> v = {1,-1,1,-1};
    cout<<subArrayWithSumZero(v);
    return 0;
}