#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        if (n < 38){
            if (n == 0 || n == 4 || n == 8 ||
                n == 14 || n == 20 || n == 24 ||
                n == 28 || n == 34) cout << "Black\n";
            else cout << "White\n";
        }
        else {
            int last = 4 + (n - 4) / 34 * 34;
            if (n == last || n == last + 4 ||
                n == last + 16 || n == last + 20 ||
                n == last + 24) cout << "Black\n";
            else cout << "White\n";
        }
    }
}