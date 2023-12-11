#include <bits/stdc++.h>
using namespace std;
void write_to_b(bool b[], int pos, int x){
    pos+=19;
    for(int i=0; i<20; i++) b[pos-i]=(x>>i)&1;
}
int read_from_b(bool b[], int pos){
    int res=0;
    for(int i=0; i<20; i++) (res*=2)+=b[pos+i];
    return res;
}
void update(bool b[], int x){
    if(!b[x]) b[x]=1;
    else{
        int n=read_from_b(b, 1000000);
        n++;
        write_to_b(b, 1000000+n*20, x);
        write_to_b(b, 1000000, n);
    }
}
void get(bool b[], int &n, int res[]){
    n=read_from_b(b, 1000000);
    for(int i=0; i<n; i++) res[i]=read_from_b(b, 1000000+(i+1)*20);
    for(int i=0; i<1000000; i++) if(b[i]){
        res[n]=i;
        n++;
    }
}