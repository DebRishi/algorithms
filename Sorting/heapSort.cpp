#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
    public:
    void maxHeapify(vector<int>& arr,int n,int i) {
        int maxNode = i;
        int lnode = 2*i + 1;
        int rnode = 2*i + 2;
        if(lnode < n && arr[maxNode] < arr[lnode])
            maxNode = lnode;
        if(rnode < n && arr[maxNode] < arr[rnode])
            maxNode = rnode;
        if(maxNode != i) {
            swap(arr[i],arr[maxNode]);
            maxHeapify(arr,n,maxNode);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = n/2 ; i >= 0 ; i--)
            maxHeapify(arr,n,i);
        for(int i = n-1 ; i >= 0 ; i--) {
            swap(arr[i],arr[0]);
            maxHeapify(arr,i,0);
        }
    }
};

int main() {
    HeapSort h;
    vector<int> v = {10,15,21,30,18,19};
    h.heapSort(v);
    for(auto i : v)
        cout<<i<<" ";
    return 0;
}