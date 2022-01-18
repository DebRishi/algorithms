#include <iostream>
#include <vector>

using namespace std;

int search(int * arr,int key,int low,int high) {
    if(low > high) {
        return -1;
    }

    int mid = low + (high-low)/2;

    if(arr[mid] == key) {
        return mid;
    }

    if(arr[low] <= arr[mid]) {
        if(key >= arr[low] && key <= arr[mid]) {
            return search(arr,key,low,mid-1);
        }
        else {
            return search(arr,key,mid+1,high);
        }
    }
    else {
        if(key >= arr[mid] && key <= arr[high]) {
            return search(arr,key,mid+1,high);
        }
        else {
            return search(arr,key,low,mid-1);
        }
    }
}

int main() {
    int arr[] = {30,40,50,10,20};
    cout<<search(arr,10,0,4);
    return 0;
}