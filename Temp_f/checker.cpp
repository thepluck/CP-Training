#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string task = "KNAPSACK";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int t = 1; t <= 20; t++){
        ofstream inp(task + ".inp");
        int n = size_t(rng()) % 10005;
        int q = size_t(rng()) % 10005;
        inp << n << ' ' << q << '\n';
        for (int i = 1; i <= n; i++)
            inp << size_t(rng()) % 10005 << " \n"[i == n];
        for (int i = 1; i <= q; i++)
            inp << size_t(rng()) % 10005 << " \n"[i == q];
        inp.close();
        system("./solution");
        system(("./" + task).data());
        if (system(("diff " + task + ".out " + task + ".ans").data()))
            return cout << "WRONG\n", 0;
    }
}