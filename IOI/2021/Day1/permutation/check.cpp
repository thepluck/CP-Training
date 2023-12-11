#include <bits/stdc++.h>


using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

vector <int> rand_permutation(int n) {
    vector <int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    return p;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    system("./compile_cpp.sh");
    while (true) {
        auto p = rand_permutation(10);
        ofstream out("sample.in");
        out << p.size() << '\n';
        for (int x : p) out << x << ' ';
        out.close();
        if (system("./permutation < sample.in")) {
            for (int x : p) cerr << x << ' ';
            break;
        }
    }
}