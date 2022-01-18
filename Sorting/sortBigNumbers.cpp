#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareBigNumbers(string s1,string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1 < n2) {
        return true;
    }
    else if(n1 > n2) {
        return false;
    }
    else {
        for(int i = 0 ; i < n1 ; i++) {
            if(s1[i] < s2[i]) {
                return true;
            }
            if(s1[i] > s2[i]) {
                return false;
            }
        }
        return false;
    }
}

void sortBigNumbers(vector <string> & arr) {
    sort(arr.begin(),arr.end(),compareBigNumbers);
}

int main() {
    vector <string> big_num = {"1","2","100","12303479849857341718340192371","3084193741082937","3084193741082938","111","200"};
    sortBigNumbers(big_num);
    for(auto i : big_num) {
        cout<<i<<" ";
    }
    return 0;
}