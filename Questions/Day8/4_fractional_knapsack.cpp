#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define pii pair<int,int>

struct Item {
    int value;
    int weight;
};

bool compare(Item & a,Item & b) {
    double v1 = (double)a.value/a.weight;
    double v2 = (double)b.value/b.weight;
    return v1 > v2;
}

double fractionalKnapsack(vector<Item> items,int weight) {
    sort(items.begin(),items.end(),compare);
    double ans = 0;
    for(auto item : items) {
        if(weight >= item.weight) {
            ans += item.value;
            weight -= item.weight;
            continue;
        }
        double v = (double)item.value/item.weight;
        ans += v * weight;
        weight = 0;
        break;
    }
    return ans;
}

int main() {
    int n = 3;
    int max_weight = 50;
    vector<int> values = {60,100,120};
    vector<int> weight = {10,20,30};
    vector<Item> items;
    for(int i = 0 ; i < n ; i++) {
        items.push_back({values[i],weight[i]});
    }
    cout<<fractionalKnapsack(items,max_weight);
    return 0;
}