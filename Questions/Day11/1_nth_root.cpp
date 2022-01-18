#include<iostream>
using namespace std;

double myPow(double n,int x) {
    if(x == 0)
        return 1;
    if(x < 0) {
        n = 1/n;
        x = -1;
    }
    return x%2 ? n*myPow(n,x-1) : myPow(n*n,x/2);
}

double NthRoot(double n,int x) {
    double low = 1;
    double high = n;
    double limit = 1e-6;
    while((high-low) > limit) {
        double mid = low + (high-low)/2.0;
        if(myPow(mid,x) < n) 
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main() {
    cout<<NthRoot(9,2);
}