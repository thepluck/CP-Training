#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);
    vector <string> color = {"Red", "Orange", "Yellow", "Green", "Blue", "Violet"};
    string color1, color2; cin >> color1 >> color2;
    int p1 = find(color.begin(), color.end(), color1) - color.begin();
    int p2 = find(color.begin(), color.end(), color2) - color.begin();
    switch ((p2 - p1 + 6) % 6) {
        case 0: cout << "Same"; break;
        case 1: cout << "Adjacent"; break;
        case 2: cout << color[(p1 + 1) % 6]; break;
        case 3: cout << "Complementary"; break;
        case 4: cout << color[(p2 + 1) % 6]; break;
        case 5: cout << "Adjacent"; break;
    }
}