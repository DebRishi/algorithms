#include <iostream>
#include <vector>
using namespace std;
#define vi vector <int>
#define vvi vector <vector <int>>

void generate(vvi & ans,vi & num,vi subset,int i) {
    if(i == num.size()) {
        ans.push_back(subset);
        return;
    }

    // Don't want to add the element
    generate(ans,num,subset,i+1);
    subset.push_back(num[i]);

    // Want to add the element
    generate(ans,num,subset,i+1);
}

vvi powerSet(vi num) {
    vvi ans;
    generate(ans,num,{},0);
    return ans;
}

int main() {
    for(auto i : powerSet({1,2,3})) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}