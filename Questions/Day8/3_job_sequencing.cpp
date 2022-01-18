#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compare(Job a,Job b) {
    return a.profit > b.profit;
}

vector<string> jobSequencing(vector<Job> jobs) {
    int max = 0;
    for(auto job : jobs) {
        max = std::max(max,job.deadline);
    }
    sort(jobs.begin(),jobs.end(),compare);
    vector<string> seq(max,"");
    for(auto job : jobs) {
        for(int i = job.deadline-1 ; i >= 0 ; i--) {
            if(seq[i] == "") {
                seq[i] = job.id;
                break;
            }
        }
    }
    return seq;
}

int main() {
    vector<Job> jobs = {
        {"J1",4,20},
        {"J2",5,60},
        {"J3",6,70},
        {"J4",6,65},
        {"J5",4,25},
        {"J6",2,80},
        {"J7",2,10},
        {"J8",2,22}
    };
    vector<string> seq = jobSequencing(jobs);
    for(auto j : seq) {
        cout<<j<<" ";
    }
    cout<<endl;
    return 0;
}