#include "mushrooms.h"
#include <bits/stdc++.h>

using namespace std;

int count_mushrooms(int N) {
    if (N <= 227) {
        int cnt = 1;
        for (int i = 1; i < N; i++)
            cnt += !use_machine({0, i});
        return cnt;
    }
    vector <int> pos[2];
    pos[0].push_back(0);
    
    int ptr = 81, cnt = pos[0].size();
    while (ptr < N) {
        if (pos[0].size() >= pos[1].size()) {
            vector <int> tmp; int len = 0;
            for (int i = 0; i < pos[0].size() 
            && ptr < N; i++, ptr++) {
                tmp.push_back(ptr); len++;
                tmp.push_back(pos[0][i]);
            }
            int x = use_machine(tmp);
            cnt += len - x / 2 - x % 2;
            pos[x % 2].push_back(tmp[0]);
        } else {
            vector <int> tmp;
            for (int i = 0; i < pos[1].size() 
            && ptr < N; i++, ptr++) {
                tmp.push_back(ptr);
                tmp.push_back(pos[1][i]);
            }
            int x = use_machine(tmp);
            cnt += x / 2 + x % 2;
            pos[1 - x % 2].push_back(tmp[0]);     
        }
    }
    return cnt;
}
