#include<iostream>
#include<vector>
using namespace std;

// MEMOIZATION
class Solution {
  public:
    vector<vector<vector<int>>> memo;
    
    int solve(string str,int i,int j,int isTrue) {
        if(i == j) {
            if(isTrue)
                return str[i] == 'T';
            else
                return str[i] == 'F';
        }
        
        if(memo[i][j][isTrue] != -1)
            return memo[i][j][isTrue];
        
        int ans = 0;
        int leftT;
        int leftF;
        int rightT;
        int rightF;

        for(int k = i+1 ; k < j ; k += 2) {
            // LEFT -> TRUE
            if(memo[i][k-1][true] != -1)
                leftT = memo[i][k-1][true];
            else
                leftT = solve(str,i,k-1,true);

            // LEFT -> FALSE
            if(memo[i][k-1][false] != -1)
                leftF = memo[i][k-1][false];
            else
                leftF = solve(str,i,k-1,false);

            // RIGHT -> TRUE    
            if(memo[k+1][j][true] != -1)
                rightT = memo[k+1][j][true];
            else
                rightT = solve(str,k+1,j,true);

            // RIGHT -> FALSE
            if(memo[k+1][j][false] != -1)
                rightF = memo[k+1][j][0];
            else
                rightF = solve(str,k+1,j,false);

            if(str[k] == '&') {
                if(isTrue)
                    ans += leftT*rightT;
                else
                    ans += leftF*rightF + leftT*rightF + leftF*rightT;
            }
            else if(str[k] == '|') {
                if(isTrue)
                    ans += leftT*rightT + leftT*rightF + leftF*rightT;
                else
                    ans += leftF*rightF;
            }
            else if(str[k] == '^') {
                if(isTrue)
                    ans += leftT*rightF + leftF*rightT;
                else
                    ans += leftT*rightT + leftF*rightF;
            }
        }
        return memo[i][j][isTrue] = ans;
    }
    
    int countWays(string str) {
        int n = str.size();
        memo = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(str,0,n-1,true);
    }
};

// RECURSIVE
// class Solution {
//   public:
//     int solve(string str,int i,int j,int isTrue) {
//         if(i == j) {
//             if(isTrue)
//                 return str[i] == 'T';
//             else
//                 return str[i] == 'F';
//         }
        
//         int ans = 0;

//         for(int k = i+1 ; k <= j-1 ; k = k + 2) {
//             int leftT = solve(str,i,k-1,true);
//             int leftF = solve(str,i,k-1,false);
//             int rightT = solve(str,k+1,j,true);
//             int rightF = solve(str,k+1,j,false);
            
//             if(str[k] == '&') {
//                 if(isTrue)
//                     ans += leftT*rightT;
//                 else
//                     ans += leftF*rightF + leftT*rightF + leftF*rightT;
//             }
//             else if(str[k] == '|') {
//                 if(isTrue)
//                     ans += leftT*rightT + leftT*rightF + leftF*rightT;
//                 else
//                     ans += leftF*rightF;
//             }
//             else if(str[k] == '^') {
//                 if(isTrue)
//                     ans += leftT*rightF + leftF*rightT;
//                 else
//                     ans += leftT*rightT + leftF*rightF;
//             }
//         }

//         return ans;
//     }
    
//     int countWays(string str) {
//         int n = str.size();
//         return solve(str,0,n-1,true);
//     }
// };

int main() {
    string str = "T|T&F^T";
    Solution s;
    cout<<s.countWays(str);
    return 0;
}