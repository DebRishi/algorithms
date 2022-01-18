#include<iostream>
#include<vector>
using namespace std;
#define vvs vector<vector<string>>
#define vs vector<string>

bool isPalindrome(string str,int start,int end) {
    while(start <= end) {
        if(str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void helper(string str,vs path,vvs & ans,int index = 0) {
    if(index == str.length()) {
        ans.push_back(path);
        return;
    }
    for(int i = index ; i < str.length() ; i++) {
        if(isPalindrome(str,index,i)) {
            path.push_back(str.substr(index,i+1-index));
            helper(str,path,ans,i+1);
            path.pop_back();
        }
    }
}

vvs partition(string str) {
    vs path;
    vvs ans;
    helper(str,path,ans);
    return ans;
}

int main() {
    string str = "aab";
    vvs ans = partition(str);
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
}