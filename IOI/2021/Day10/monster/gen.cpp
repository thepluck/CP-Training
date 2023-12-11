#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector <int> p(7);
    iota(p.begin(), p.end(), 0);
    do {
        ofstream inp("input.txt");
        inp << "7\n";
        for (int x : p) inp << x << ' ';
        inp.close();
        if (system("./grader < input.txt")) break; 
    } while (next_permutation(p.begin(), p.end()));
}