/// findland codelearn
/// find largest rectangle which has max - min <= k
#include <bits/stdc++.h>
using namespace std;

deque <int> dqmin, dqmax;
int minarr[305], maxarr[305];
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

int find_Land(int k, vector<vector<int>> land)
{
    int n = land.size(), m = land[0].size(), ans = 0;
    for (int i = 0; i < n; i++){
        for (int x = 0; x < m; x++){
            minarr[x] = inf; maxarr[x] = ninf;
        }
        for (int j = i; j < n; j++){
            dqmin.clear(); dqmax.clear();
            for (int x = 0; x < m; x++){
                chkmin(minarr[x], land[j][x]);
                chkmax(maxarr[x], land[j][x]);
            }
            for (int x = 0, y = 0; x < m; x++){
                if (!dqmin.empty() && dqmin.front() < x) dqmin.pop_front(); 
                if (!dqmax.empty() && dqmax.front() < x) dqmax.pop_front(); 
                while (y < m){
                    if (dqmin.empty() || dqmax.empty()){
                        while (!dqmin.empty() && minarr[dqmin.back()] >= minarr[y]) dqmin.pop_back();
                        while (!dqmax.empty() && maxarr[dqmax.back()] <= maxarr[y]) dqmax.pop_back();
                        dqmax.push_back(y); dqmin.push_back(y); y++;
                    }
                    else if (max(maxarr[dqmax.front()], maxarr[y]) - min(minarr[dqmin.front()], minarr[y]) <= k){
                        while (!dqmin.empty() && minarr[dqmin.back()] >= minarr[y]) dqmin.pop_back();
                        while (!dqmax.empty() && maxarr[dqmax.back()] <= maxarr[y]) dqmax.pop_back();
                        dqmax.push_back(y); dqmin.push_back(y); y++;
                    }
                    else break;
                }
                if (maxarr[dqmax.front()] - minarr[dqmin.front()] <= k) chkmax(ans, (y - x) * (j - i + 1));
            }
        }
    }
    return ans;
}

int main(){
    vector <vector <int>> land = {{4,2,1,4},{7,7,5,7},{3,8,5,1},{4,7,7,1}};
    cout << find_Land(1, land) << '\n';
}