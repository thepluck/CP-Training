#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    system("build route");
    for (int i = 0; i < 10; i++) {
        string in = "input/input_" + to_string(i) + ".txt";
        string out = "submission/output_" + to_string(i) + ".txt";
        system(("run route -i " + in + " -o " + out).data());
    }
}