#include<bits/stdc++.h>
using namespace std;

// Hackerrank - Sorting

int freq[201];

int getMedian(int days) {
    int cnt = 0;
    int med = ceil((float)days/2);
    for(int i = 0 ; i < 201 ; i++) {
        cnt += freq[i];
        if(cnt > med)
            return 2 * i;
        if(cnt == med) {
            if(days & 1)
                return 2 * i;
            else {
                for(int j = i+1 ; j < 201 ; j++)
                    if(freq[i])
                        return i + j;
            }
        }
    }
    return -1;
}

int solve(vector<int>& nums,int days) {
    memset(freq,0,sizeof(freq));
    for(int i = 0 ; i < days ; i++)
        freq[nums[i]]++;
    int ans = 0;
    for(int i = days ; i < (int)nums.size() ; i++) {
        if(getMedian(days) <= nums[i])
            ans++;
        freq[nums[i]]++;
        freq[nums[i-days]]--;
    }
    return ans;
}

int main() {
    int size,days,temp;
    cin>>size>>days;
    vector<int> nums;
    for(int i = 0 ; i < size ; i++) {
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<solve(nums,days);
    return 0;
}
