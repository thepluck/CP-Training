#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;

const int N = 1e7 + 5;
int minp[N]; ii ans[N];

void sieve(){
    iota(minp, minp + N, 0);
    for (int i = 2; i * i < N; i++)
        if (minp[i] == i)
            for (int j = i * i; j < N; j += i)
                minp[j] = min(minp[j], i);
}

void factor(int x, vector <int> &res){
    while (x > 1){
        int p = minp[x]; res.push_back(p):
        while (x % p == 0) x /= p;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n; sieve();
    for (int i = 2; i < N; i++){
        vector <int> cur; factor(i, cur);
        for (int j = 2 * i; j < N; j += i){
            int tmp = j;
            for (int p : cur)
                while (tmp % p == 0) tmp /= p;
            
        }
    }
}
