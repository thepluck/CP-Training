#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=60,M=1<<23;
int n,k,d[N][N],a[N],C;

void read()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++) cin>>d[i][j];
}

int vis[N];

int cost(vi &vt)
{
    int res=d[0][vt[0]]+d[vt.back()][0];
    for (int i=0;i<(int)vt.size()-1;i++) res+=d[vt[i]][vt[i+1]];
    return res;
}

void optimize_path(vi &ans,int &dis)
{
    int len=ans.size();
    bool check=true;
    while (check)
    {
        check=false;
        for (int i=0;i<len;i++)
            for (int j=i+1;j<len;j++)
            {
                swap(ans[i],ans[j]);
                int c=cost(ans);
                if (c<dis) dis=c,check=true;
                else swap(ans[i],ans[j]);
            }
    }
}

void optimize_vertex(vi &ans,int &dis,int &cnt)
{
    for (int i=0;i<(int)ans.size();i++)
        if (cnt-a[ans[i]]>=k) cnt-=a[ans[i]],ans.erase(ans.begin()+i);
    dis=cost(ans);
}

double f(int num,int dis) {return (double)(num+C)/dis/dis+Int(0,1);}
void greedy(vi &vt,int &res)
{
    int cnt=0,u=0,dis=0;
    vector<int> ans;
    for (int i=1;i<=n;i++) vis[i]=0;
    while (cnt<k)
    {
        int nxt=0;
        double mx=-1e9;
        for (int v=1;v<=n;v++)
            if (!vis[v] && f(a[v],d[u][v])>mx) mx=f(a[v],d[u][v]),nxt=v;
        dis+=d[u][nxt];
        vis[nxt]=1;
        u=nxt;
        cnt+=a[u];
        ans.eb(u);
    }
    dis+=d[u][0];
    optimize_vertex(ans,dis,cnt);
    optimize_path(ans,dis);
    vt=ans;
    res=dis;
}

int p[N];

void process()
{
    int res=1e9;
    vi ans;
    for (int i=1;i<=1;i++)
        for (C=0;C<=10000;C++)
        {
            vi vt;
            int dis;
            greedy(vt,dis);
            if (dis<res) res=dis,ans=vt;
        }
    /*n=ans.size();
    for (int i=1;i<=n;i++) p[i]=ans[i-1];*/
    cout<<res<<"\n"<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
}

int sum[M],dp[M][24],trace[M][24];

void sub2()
{
    int mx=(1<<n)-1;
    for (int mask=0;mask<=mx;mask++)
        for (int i=1;i<=n;i++) dp[mask][i]=1e9;
    for (int i=1;i<=n;i++) sum[1<<(i-1)]=a[p[i]],dp[1<<(i-1)][i]=d[0][p[i]];
    for (int i=0;i<=mx;i++) sum[i]=sum[i-(i&-i)]+sum[i&-i];
    pii best;
    int res=1e9;
    for (int mask=0;mask<=mx;mask++)
        for (int i=1;i<=n;i++)
            if (dp[mask][i]<1e9)
            {
                int dis=dp[mask][i];
                if (sum[mask]>=k)
                {
                    if (res>dis+d[p[i]][0])
                    {
                        res=dis+d[p[i]][0];
                        best=mp(mask,i);
                    }
                }
                for (int j=1;j<=n;j++)
                    if (((mask>>(j-1))&1)==0)
                    {
                        int nw_mask=mask | (1<<(j-1));
                        if (dp[nw_mask][j]>dis+d[p[i]][p[j]]) dp[nw_mask][j]=dis+d[p[i]][p[j]],trace[nw_mask][j]=i;
                    }
            }
    vi ans;
    while (best.fi)
    {
        ans.eb(best.se);
        int tmp=best.se;
        best.se=trace[best.fi][best.se];
        best.fi ^= (1<<(tmp-1));
    }
    reverse(all(ans));
    cout<<res<<"\n"<<ans.size()<<"\n";
    for (int x : ans) cout<<p[x]<<" ";
}

int main()
{
    freopen("input_9.txt","r",stdin);
    freopen("output_9.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    //sub2();
    return 0;
}
