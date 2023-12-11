#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MAX=100000+5,inf=1e9;
#define pb push_back
#define int long long
int randint(int l,int r){
    return uniform_int_distribution < int > (l,r) (rng);
}
using ii = pair < int , int >;
void minn(int &a,int b){
    if(b<a) a=b;
}
void maxx(int &a,int b){
    if(b>a) a=b;
}
struct pt{
    int x, y;
    pt(){}
    pt(int x,int y): x(x), y(y) {}
    bool operator < (const pt &o) const{
        if(x==o.x) return y<o.y;
        else return x<o.x;
    }
    bool operator == (const pt &o) const{
        return (x==o.x) && y==o.y;
    }
    bool operator != (const pt &o) const{
        return (x!=o.x) || y!=o.y;
    }
    pt operator + (const pt &o) const{
        return pt(x+o.x,y+o.y);
    }
    pt operator - (const pt &o) const{
        return pt(x-o.x,y-o.y);
    }
    pt operator * (const int &o) const{
        return pt(x*o,y*o);
    }
    pt operator / (const int &o) const{
        return pt(x/o,y/o);
    }
    int abs(){
        return sqrt(x*x+y*y);
    }
};
int dot ( pt a, pt b){
    return a.x*b.x+a.y*b.y;
}
int cross (pt a,pt b){
    return a.x*b.y-a.y*b.x;
}
int orient(pt a,pt b,pt c){
    return cross(b-a,c-b);
}
struct line{
    pt v;
    int c;
    line(){}
    line(pt v,int c): v(v),c(c){}
    line(pt a,pt b): v(b-a),c(cross(v,a)){}
    line dich(int dis){
        return {v,c+dis*v.abs()};
    }
    int side(const pt &o){
        return cross(v,o)-c;
    }

};
pt giao ( line a, line b) {
    int d=cross(b.v,a.v);
    return (a.v*b.c-b.v*a.c)/d;
}
int st[MAX];
int a[MAX],b[MAX],to[MAX];
int vs[MAX];
int cn,N;
vector < int > pr[MAX];
using poly = vector < pt > ;
poly V[MAX];
int SA,SB;
void DFS(int v,int pa){
    vs[v]=++cn;
    st[cn]=pa;
    for(int u:pr[v])if(u!=pa){
        int x=to[u]-v;
        if(!vs[x]) {
            DFS(x,u);
        }
        else if(vs[x]<cn) {
            //cout<<v<<' '<<x<<' '<<N+1<<'\n';
            ++N;
            int suma=a[u],sumb=b[u];
            for(int i=cn;i>vs[x];i--){
                suma+=a[st[i]];
                sumb+=b[st[i]];
            }
            SA+=suma;SB+=sumb;
            V[N].pb(pt(suma-a[u],sumb-b[u]));
            for(int i=cn;i>vs[x];i--)
                V[N].pb(pt(suma-a[st[i]],sumb-b[st[i]]));
        }
    }
    cn--;
}
pt P[MAX];
//int ow=0;
void makepoly(poly &A){
    //ow++;
    sort(A.begin(),A.end());
    int n=0;
    for(pt u:A)if(u!=P[n]){
        while(n>1 && orient(P[n-1],P[n],u)<0) n--;
        //if(ow==20) cout<<u.x<<' '<<u.y<<' '<<n<<'\n';
        //if(ow==20 && n>1) cout<<orient(P[n-2],P[n-1],u)<<'\n';
        P[++n]=u;
    }
    A.clear();
    A.insert(A.begin(),P+1,P+1+n);
    //cout<<n<<'\n';
   // for(pt u:A) cout<<u.x<<' '<<u.y<<'\n';
}
poly C;
pt oo=pt(0,0);
void combpoly(poly &A,poly &B){
    C.clear();
    int n=A.size(),m=B.size();
    if(n==1){
        for(pt u:B)C.pb(u+A[0]);
        A=C;return ;
    }
    if(m==1){
        for(pt u:A)C.pb(u+B[0]);
        A=C;return ;
    }

    C.pb(A[0]+B[0]);
    B.pb(oo);
    pt q=B[1]-B[0];
    int v=1;
    for(int u=1;u<n;u++){
        pt p=A[u]-A[u-1];
        while(v<m && cross(p,q)<0){
            C.pb(C.back()+q);
            v++;
            q=B[v]-B[v-1];
        }
        C.pb(C.back()+p);
    }
    while(v<m){
        C.pb(C.back()+q);
        v++;
        q=B[v]-B[v-1];
    }
    A=C;return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("cactusmst.inp","r",stdin);
    //freopen("PTRANG.inp","r",stdin);freopen("PTRANG.out","w",stdout);
    //cout<<orient( pt(74572,82006),pt(74749, 84435),pt(83218, 74941));return 0;
    int n,m;
    cin>>n>>m;
    int Sa=0,Sb=0;
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y>>a[i]>>b[i];
        Sa+=a[i];Sb+=b[i];
        to[i]=x+y;
        pr[x].pb(i);
        pr[y].pb(i);
    }
    DFS(1,0);
    Sa-=SA;Sb-=SB;
    //cout<<Sa<<' '<<Sb<<'\n';
    for(int i=1;i<=N;i++){
        makepoly(V[i]);
        //cout<<V[i].size()<<'\n';
        //for(pt u:V[i]) cout<<u.x<<' '<<u.y<<'\n';
    }
    //for(int i=2;i<=N;i++) combpoly(V[1],V[i]);
    for(int j=1;(1<<j-1)<N;j++){
        for(int i=1;i+(1<<j-1)<=N;i+=(1<<j)){
            combpoly(V[i],V[i+(1<<j-1)]);
            //cout<<i<<' '<<i+(1<<j-1)<<'\n';
        }
    }
    int ans=1e18;
    for(pt u:V[1]){
        minn(ans,(u.x+Sa)*(u.y+Sb));
    }
    cout<<ans<<'\n';
}
