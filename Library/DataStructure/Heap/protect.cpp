#define fi first
#define se second
#include <iostream>
#include <queue>
using namespace std;

typedef pair <int, int> ii;
priority_queue <ii> heap;
int n, s, cnt, sum; ii a;

int main(){
    freopen("protect.inp", "rt", stdin);
    freopen("protect.out", "wt", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> a.se >> a.fi;
        heap.push(a); sum += a.se;
    }
    while (!heap.empty() && s > 0){
        ii temp = heap.top();
        heap.pop();
        int d = temp.se / temp.fi;
        d = min(s, d);
        cnt += d * temp.fi; s -= d;
        temp.second -= d * temp.fi;
        if (temp.se != 0){
            if (temp.se < temp.fi)
                temp.fi = temp.se;
            heap.push(temp);
        }
    }
    cout << sum - cnt;
}
