#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("qbheap.inp", "r", stdin);
    priority_queue <int> heap;
    string s;
    for(; getline(cin, s);){
        if (s[0] == '+'){
            if (heap.size() < 15000) heap.push(stoi(s));
        }
        else if (!heap.empty()){
            int t = heap.top();
            while (!heap.empty() && heap.top() == t) heap.pop();
        }
    }
    vector <int> ans;
    while (!heap.empty()){
        int t = heap.top();
        ans.push_back(t);
        while (!heap.empty() && heap.top() == t) heap.pop();
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << '\n';
}
