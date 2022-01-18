#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> & num) {
    int low = 0;
    int mid = 0;
    int high = num.size()-1;
    while(mid <= high) {
        if(num[mid] == 0) {
            swap(num[mid++],num[low++]);
        }
        else if(num[mid] == 2) {
            swap(num[mid],num[high--]);
        }
        else {
            mid++;
        }
    }
}

int main() {
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}