#include <bits/stdc++.h>
using namespace std;

struct node{
    int l,r,vl,vr,vm,lz;node():lz(0),vm(0){}
} seg[40005];

void build(int i,int l,int r){
    seg[i].l=l;seg[i].r=r;if(l==r){seg[i].vm=seg[i].vl=seg[i].vr=1;return;}
    int m=(l+r)/2;build(i*2,l,m);build(i*2+1,m+1,r);
    seg[i].vm=seg[i].vl=seg[i].vr=r-l+1;
}

void lazy_down(int i){
    if(seg[i].lz==1)seg[i].vm=seg[i].vl=seg[i].vr=seg[i].r-seg[i].l+1;
    else if(seg[i].lz==2)seg[i].vm=seg[i].vl=seg[i].vr=0;else return;
    if(seg[i].l!=seg[i].r)seg[i*2].lz=seg[i*2+1].lz=seg[i].lz;seg[i].lz=0;
}

void update(int i,int l,int r,int t){
    lazy_down(i);if(seg[i].l>r||seg[i].r<l)return;
    if(seg[i].l>=l&&seg[i].r<=r){
        if(t==1)seg[i].vm=seg[i].vl=seg[i].vr=seg[i].r-seg[i].l+1;
        else seg[i].vm=seg[i].vl=seg[i].vr=0;
        if(seg[i].l!=seg[i].r)seg[i*2].lz=seg[i*2+1].lz=t;return;
    }
    update(i*2,l,r,t);update(i*2+1,l,r,t);
    seg[i].vl=seg[i*2].vl+(seg[i*2].vl==seg[i*2].r-seg[i*2].l+1?seg[i*2+1].vl:0);
    seg[i].vr=seg[i*2+1].vr+(seg[i*2+1].vr==seg[i*2+1].r-seg[i*2+1].l+1?seg[i*2].vr:0);
    seg[i].vm=max({seg[i*2].vm,seg[i*2+1].vm,seg[i*2].vr+seg[i*2+1].vl});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;build(1,1,n);int cmd,l,r;
    while(q--){
        cin>>cmd;if(cmd==3)cout<<seg[1].vm<<'\n';
        if(cmd==1){cin>>l>>r;update(1,l,r,1);}if(cmd==2){cin>>l>>r;update(1,l,r,2);}
    }
}