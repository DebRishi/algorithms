#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector <int> prices) {
    int minPrice = INT_MAX;
    int profit = 0;
    for(auto p : prices) {
        minPrice = min(minPrice,p);
        profit = max(profit,p - minPrice);
    }
    return profit;
}

int main() {
    cout<<maxProfit({7,1,5,3,6,4})<<endl;
    return 0;
}