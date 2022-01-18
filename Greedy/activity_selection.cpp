#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> a,vector<int> b) {
    if(a[2] != b[2]) 
        return a[2] < b[2];
    else
        return a[1] <= b[2];
}

vector<vector<int>> maxActivities(vector<int> start,vector<int> finish,int n) {
    vector<vector<int>> act;
    for(int i = 0 ; i < n ; i++) {
        act.push_back({i+1,start[i],finish[i]});
    }
    sort(act.begin(),act.end(),compare);
    vector<vector<int>> ans;
    int end = -1;
    for(auto a : act) {
        if(a[1] > end) {
            ans.push_back(a);
            end = a[2];
        }
    }
    return ans;
}

// PRIORITY QUEUE
// int maxActivities(vector<int> start,vector<int> finish,int n) {
//     priority_queue<pii,vector<pii>,greater<pii>> minheap;
//     for(int i = 0 ; i < n ; i++) minheap.push({finish[i],start[i]});
//     int ans = 0;
//     int end = -1;
//     while(!minheap.empty()) {
//         pii x = minheap.top();
//         minheap.pop();
//         if(x.second > end) {
//             end = x.first;
//             ans++;
//         }
//     }
//     return ans;
// }

int main() {
    vector <int> start = {1,3,0,5,8,5};
    vector <int> finish = {2,4,6,7,9,9};
    vector<vector<int>> ans = maxActivities(start,finish,6);
    for(auto a : ans) {
        cout<<a[0]<<" -> "<<a[1]<<" "<<a[2]<<endl;
    }
    return 0;
}