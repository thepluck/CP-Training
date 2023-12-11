#include <bits/stdc++.h>
using namespace std;
void update(bool b[], int x){
    b[x]=1;
}
void get(bool b[], int &n, int res[]){
    n=0;
    for(int i=0; i<1000000; i++) if(b[i]){
        res[n]=i;
        n++;
    }
}