#include<iostream>
using namespace std;

void countSort(int arr[],int n,int exp) {
    int freq[10] = {0};

    for(int i = 0 ; i < n ; i++)
        freq[(arr[i]/exp)%10]++;

    for(int i = 1 ; i < 10 ; i++)
        freq[i] += freq[i-1];
    
    int ans[n];
    for(int i = n-1 ; i >= 0 ; i--) {
        int pos = freq[(arr[i]/exp)%10]--;
        ans[pos-1] = arr[i];
    }

    for(int i = 0 ; i < n ; i++)
        arr[i] = ans[i];
}

void radixSort(int arr[],int n) {
    int maxNum = arr[0];
    for(int i = 0 ; i < n ; i++)
        maxNum = max(maxNum,arr[i]);
    int exp = 1;
    while(exp <= maxNum) {
        countSort(arr,n,exp);
        exp = exp * 10;
    }
}

int main() {
    int arr[] = {40,12,45,32,33,1,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    return 0;
}