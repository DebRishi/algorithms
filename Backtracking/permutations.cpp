#include <iostream>
#include <vector>

using namespace std;

void getPermutations(vector <vector <int>> & r,vector <int> & n,int pos = 0) {
    if(pos == n.size()) {
        r.push_back(n);
        return;
    }
    for(int i = pos ; i < n.size() ; i++) {
        swap(n[i],n[pos]);
        getPermutations(r,n,pos+1);
        swap(n[i],n[pos]);
    }
}

int main() {
    vector <int> v = {1,2,3,4};
    vector <vector <int>> result;
    getPermutations(result,v);
    for (auto i : result) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}