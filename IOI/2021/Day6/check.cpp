#include <bits/stdc++.h>

using namespace std;

int main() {
    system("g++ -std=c++17 -O2 gen.cpp -o gen");
    system("g++ -std=c++17 -O2 B.cpp -o B");
    system("g++ -std=c++17 -O2 B_full.cpp -o B_full");
    while (true) {
        system("run gen -o in");
        system("run B -i in -o out");
        system("run B_full -i in -o ans");
        if (system("diff out ans")) break;
    }
}