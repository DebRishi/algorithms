#include <iostream>
#include <vector>
using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.length();
    vector <int> forces(n,0);
    
    // CALCULATING RIGHT FORCES
    int force = 0;
    for(int i = 0 ; i < n ; i++) {
        if(dominoes[i] == 'R') {
            force = n;
        }
        else if(dominoes[i] == 'L') {
            force = 0;
        }
        else {
            force = max(force-1,0);
        }
        forces[i] += force;
    }
    
    // CALCULATING LEFT FORCES
    force = 0;
    for(int i = n-1 ; i >= 0 ; i--) {
        if(dominoes[i] == 'L') {
            force = n;
        }
        else if(dominoes[i] == 'R') {
            force = 0;
        }
        else {
            force = max(force-1,0);
        }
        forces[i] -= force;
    }
    
    // GETTING THE NET FORCE AT EACH POINT
    string ans = "";
    for(auto i : forces) {
        if(i > 0) {
            ans += 'R';
        }
        else if(i < 0) {
            ans += 'L';
        }
        else {
            ans += '.';
        }
    }
    return ans;
}

int main() {
    cout<<pushDominoes(".L.R...LR..L..");
    // ans = "LL.RR.LLRRLL.."
    return 0;
}