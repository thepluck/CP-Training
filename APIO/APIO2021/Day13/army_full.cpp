#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
//#define int long long

using ii = pair < int , int > ;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
bool cmax(int &a,int b){if(b>a){a=b;return 1;}else return 0;}
using ll = long long;
const int MAX=100004,M2=1e5+1,ac=400;
int lim;
vector < int > pr[MAX];
vector < ii > ad[MAX];
int par[MAX],sz[MAX];
bool on[MAX];
int fin(int u){
    while(par[u]!=u) u=par[u];
    return u;
}
stack < int > rec;
ll res=0;
void comb(int x,int y){
    int u = fin(x),v=fin(y);
    if(u==v) return;
    if(sz[u]>sz[v])swap(u,v);
    res+=2LL*sz[v]*sz[u];
    sz[v]+=sz[u];
    par[u]=v;
}
void comb2(int x,int y){
    int u = fin(x),v=fin(y);
    if(u==v) return;
    if(sz[u]>sz[v])swap(u,v);
    res+=2LL*sz[v]*sz[u];
    sz[v]+=sz[u];
    par[u]=v;rec.push(u);
}
ll an[MAX];
void rollback(){
    while(!rec.empty()){
        int u= rec.top();rec.pop();
        int v=par[u];
        par[u]=u;
        sz[v]-=sz[u];
        res-=2LL*sz[v]*sz[u];
    }
}
int main(){
    //freopen("C.inp","r",stdin);
    int n,m,Q;
    cin>>n>>m>>Q;
    lim=sqrt(m*2);
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y;
        pr[x].pb(y);
        pr[y].pb(x);
    }
    for(int i=1,x,y;i<=Q;i++){
        cin>>x>>y;
        ad[y].pb(ii(x,i));
        an[i]=-(n-(y-x+1));
    }
    for(int i=1;i<=n;i++){
        sort(ad[i].begin(),ad[i].end(), greater < ii >());
    }
    int S=0,las=1;
    stack < ii > lis;
    for(int cs=1;cs<=n;cs++) {
        S+=int(pr[cs].size());
        if(S>=lim || cs==n){
                //cout<<las<<' '<<cs<<'\n';
            S=0;
            for(int i=1;i<=n;i++){
                par[i]=i;sz[i]=1;
                on[i]=0;
            }
            res=n;
            for(int j=las;j<cs;j++){

                while(!ad[j].empty()){
                    ii p = ad[j].back();
                    if(p.X>cs) break;
                    ad[j].pop_back();
                    lis.push(p);
                }
                int poi=j+1;
                while(!lis.empty()){
                    ii p = lis.top();lis.pop();
                    while(poi>p.X){
                        poi--;
                        on[poi]=1;
                        for(int u:pr[poi])if(on[u])
                            comb2(poi,u);
                    }
                    an[p.Y]+=res;
                }

                while(poi<=j){
                    on[poi]=0;poi++;
                }
                rollback();
            }
            //for(int i=1;i<=n;i++) cout<<sz[i]<<' '<<par[i]<<' ';cout<<'\n';
            las=cs+1;
            for(int j=cs;j<=n;j++){
                on[j]=1;
                for(int u:pr[j])if(on[u])
                    comb(j,u);
                int poi=cs;
                while(!ad[j].empty()){
                    ii p = ad[j].back();
                    if(p.X>cs) break;
                    ad[j].pop_back();
                    lis.push(p);
                }
                while(!lis.empty()){
                    ii p = lis.top();lis.pop();
                    while(poi>p.X){
                        poi--;
                        on[poi]=1;
                        for(int u:pr[poi])if(on[u])
                            comb2(poi,u);
                    }
                    an[p.Y]+=res;
                }
                while(poi<cs){
                    on[poi]=0;poi++;
                }
                rollback();
            }
        }
    }
    for(int i=1;i<=Q;i++) cout<<an[i]<<'\n';
}
