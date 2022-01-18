#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define vi vector <int>
#define vpii vector <pair <int,int>>
#define mii map <int,int>
#define pii pair <int,int>
#define F first
#define S second

bool cmp(const pii & a,const pii & b) {
    return a.S > b.S;
}

vi mostFrequent(const vi & num,int k) {
    mii freq;
    for(auto i : num) {
        freq[i] += 1;
    }
    vpii temp;
    for(auto i : freq) {
        temp.push_back({i.F,i.S});
    }
    sort(temp.begin(),temp.end(),cmp);
    vi ans;
    for(int i = 0 ; i < k ; i++) {
        ans.push_back(temp[i].F);
    }
    return ans;
}

int main() {
    vi v = {1,2,2,2,3,3,4,1,1,2};
    for(auto i : mostFrequent(v,2)) {
        cout<<i<<" ";
    }
    return 0;
}