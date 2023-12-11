#include <bits/stdc++.h>
using namespace std;
using db=long double;
int n, m;
vector <pair <int, db>> g[100001];
pair <db, db> f[100001];
bool done[100001];
void dfs(int u){
    done[u]=1;
    if(u==n){
        f[u]={0, 0};
        return;
    }
    for(auto p: g[u]){
        if(!done[p.first]) dfs(p.first);
        f[u].first+=f[p.first].first*((db(1))-p.second);
        f[u].second+=p.second+f[p.first].second*((db(1))-p.second);
    }
    f[u].first/=g[u].size();
    f[u].first+=1;
    f[u].second/=g[u].size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0, u, v, q; i<m; i++){
        cin>>u>>v>>q;
        g[u].push_back({v, (db(q))/100});
    }
    dfs(1);
    cout<<setprecision(16)<<fixed<<f[1].first/((db(1))-f[1].second);
}