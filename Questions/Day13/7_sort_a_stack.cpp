#include<iostream>
#include<stack>
using namespace std;

void recursiveInsert(stack<int>& st,int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    if(st.top() <= x) {
        st.push(x);
        return;
    }
    else {
        int temp = st.top();
        st.pop();
        recursiveInsert(st,x);
        st.push(temp);
    }
}

void extraStackInsert(stack<int>& st,int x) {
    stack<int> temp;
    while(!st.empty() && st.top() > x) {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void sortStack(stack<int>& st) {
    if(st.empty())
        return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    // recursiveInsert(st,temp);
    extraStackInsert(st,temp);
}

int main() {
    stack<int> st;
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);
    sortStack(st);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}