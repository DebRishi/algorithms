#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
    public:
    void quickSort(vector<int>& arr,int low,int hii) {
        if(low > hii)
            return;
        int mid = partition(arr,low,hii);
        quickSort(arr,low,mid-1);
        quickSort(arr,mid+1,hii);
    }

    int partition(vector<int>& arr,int low,int hii) {
        int i = low;
        int j = low;
        while(j < hii) {
            if(arr[j] < arr[hii])
                swap(arr[i++],arr[j]);
            j++;
        }
        swap(arr[i],arr[hii]);
        return i;
    }
};

int main() {
    QuickSort q;
    vector<int> arr = {4,1,3,9,7};
    q.quickSort(arr,0,4);
    for(auto i : arr)
        cout<<i<<" ";
    return 0;
}