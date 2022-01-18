#include<iostream>
#include<vector>
using namespace std;

int rotatedSearch(vector<int>& arr,int key) {
    int low = 0;
    int high = arr.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
            return mid;
        
        // left half is sorted
        if(arr[low] <= arr[mid]) {
            
            // figure out if element lies in left half
            if(key >= arr[low] && key <= arr[mid])
                high = mid-1;

            // if not it must be in left half
            else
                low = mid+1;
        }

        // right half is sorted
        else {
            
            // figure out if the element lies in right half
            if(key >= arr[mid] && key <= arr[high])
                low = mid+1;
            
            // if not it must be in right half
            else
                high = mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,8,0,1,2,3};
    cout<<rotatedSearch(arr,6);
    return 0;
}

// RECURSIVE
// int rotatedSearch(int arr[],int key,int low,int high) {
//     if(low > high)
//         return -1;
//     int mid = low + (high-low)/2;
//     if(arr[mid] == key)
//         return mid;
//     if(arr[low] <= arr[mid]) {
//         if(key >= arr[low] && key <= arr[mid])
//             return rotatedSearch(arr,key,low,mid-1);
//         else
//             return rotatedSearch(arr,key,mid+1,high);
//     }
//     else {
//         if(key >= arr[mid] && key <= arr[high])
//             return rotatedSearch(arr,key,mid+1,high);
//         else
//             return rotatedSearch(arr,key,low,mid-1);
//     }
// }

// int main() {
//     int arr[] = {4,5,6,7,8,0,1,2,3};
//     cout<<rotatedSearch(arr,6,0,8);
//     return 0;
// }