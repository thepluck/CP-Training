#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    system("build line");
    for (int i = 1; i <= 10; i++) {
        string path = "test/test0";
        path += char(i / 10 + '0');
        path += char(i % 10 + '0');
        path += '/';
        string out;
        out += char(i / 10 + '0');
        out += char(i % 10 + '0');
        out += ".out";
        system(("run line -i " + path + "line.inp -o submission/" + out).data());
    }
}