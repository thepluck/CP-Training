/*
Compiler recommendation: C++17
*/
#ifndef mxorlib

#define mxorlib
#include<bits/stdc++.h>
using namespace std;

//==========================Private function for jury system==============================//

struct Tjury{

    const int REQUESTLIMIT = 33;

    int n, a[100002];

    Tjury(){
        cout << "Enter n and array a to test:" << endl;
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
    }

    int max_xor(vector<int> &I, vector<int> &J){
        int ans = -1;
        for (int i : I)
            for (int j : J){
                if (i > n || i < 1 || j > n || j < 1 || i == j){
                    cerr << i << ' ' << j << '\n';
                    cout << "Invalid request" << endl;
                    exit(0);
                }
                ans = max(ans, a[i] ^ a[j]);
            }
        return ans;
    }

} jury;

//===================================API function=========================================//
int get_n(){
    return jury.n;
}
int max_xor(vector<int> &I, vector<int> &J){
    return jury.max_xor(I, J);
}
void answer(int i, int j){
    cout << "Answer: " << i << " " << j << endl;
    exit(0);
}

#endif
