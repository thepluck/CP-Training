#include <bits/stdc++.h>
using namespace std;
using db=long double;
int n, m;
vector <pair <int, db>> g[100001];
db f[100001];
pair <int, db> trace[100001];
bool done[100001];
pair <db, db> x[100001];
db current_ans=0;
void dfs(int u){
    done[u]=1;
    if(u==n){
        f[u]=0; 
        return;
    }
    f[u]=1e18;
    for(auto p: g[u]){
        if(!done[p.first]) dfs(p.first);
        db res=(f[p.first])*((db(1))-p.second)+p.second*current_ans+1;
        if(res<f[u]){
            f[u]=res;
            trace[u]=p;
        }
    }
}
db rebuild(){
    vector <pair <int, db>> best;
    vector <int> source;
    int u=1;
    while(u!=n){
        best.push_back(trace[u]);
        source.push_back(u);
        u=trace[u].first;
    }
    x[n]={0, 0};
    for(int i=best.size()-1; i>=0; i--){
        int u=source[i];
        auto p=best[i];
        x[u].first=x[p.first].first*((db(1))-p.second)+1;
        x[u].second=p.second+x[p.first].second*((db(1))-p.second);
    }
    return x[1].first/((db(1))-x[1].second);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0, u, v, q; i<m; i++){
        cin>>u>>v>>q;
        g[u].push_back({v, (db(q))/100});
    }
    for(int i=1; i<n; i++) trace[i]=g[i][0];
    current_ans=rebuild();
    for(int i=0; i<=4; i++){
        for(int j=1; j<=n; j++) done[j]=0;
        dfs(1);
        current_ans=rebuild();
    }
    cout<<setprecision(16)<<fixed<<current_ans;
}