#include<iostream>
using namespace std;

void countSort(int arr[],int n) {
    int minNum = arr[0];
    int maxNum = arr[0];
    for(int i = 0 ; i < n ; i++) {
        minNum = min(minNum,arr[i]);
        maxNum = max(maxNum,arr[i]);
    }

    int range = maxNum - minNum + 1;
    int freq[range] = {0};

    for(int i = 0 ; i < n ; i++)
        freq[arr[i] - minNum]++;

    for(int i = 1 ; i < n ; i++)
        freq[i] += freq[i-1];
    
    int ans[range];
    for(int i = n-1 ; i >= 0 ; i--) {
        int pos = freq[arr[i]-minNum]--;
        ans[pos-1] = arr[i];
    }

    for(int i = 0 ; i < n ; i++)
        arr[i] = ans[i];
}

int main() {
    int arr[] = {1,4,1,2,7,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr,n);
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
}