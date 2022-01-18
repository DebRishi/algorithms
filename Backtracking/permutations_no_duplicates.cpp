#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void getPermutations(vector <vector <int>> & r,vector <int> & n,int pos = 0) {
    if(pos == n.size()) {
        r.push_back(n);
        return;
    }

    unordered_set <int> duplicates;

    for(int i = pos ; i < n.size() ; i++) {
        if(duplicates.find(n[i]) == duplicates.end()) {
            duplicates.insert(n[i]);
            swap(n[i],n[pos]);
            getPermutations(r,n,pos+1);
            swap(n[i],n[pos]);
        }
    }
}

int main() {
    vector <int> v = {1,1,2,2};
    vector <vector <int>> result;
    getPermutations(result,v);
    for (auto i : result) {
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Number of Permutations : "<<result.size();
    return 0;
}