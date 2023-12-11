// Judges with GCC >= 12 only needs Ofast
// #pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int inf=1e9;
const int mod=998244353;
const int maxn=500005;
const int maxl=25;
const int maxa=1000005;
int power(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;n>>=1;
    }
    return res;
}
int n,p[maxn];
namespace Solve_left{
    struct node{
        int Min=0,num=0,lazy=0;
        node(){}
        friend node operator+(node a,node b){
            node res;res.Min=min(a.Min,b.Min);
            if(a.Min==b.Min) res.num=a.num+b.num;
            else if(a.Min<b.Min) res.num=a.num;
            else res.num=b.num;
            return res;
        }
    };
    struct ST{
        node tree[4*maxn];
        void getnew(int id,int val){
            tree[id].Min+=val;tree[id].lazy+=val;
        }
        void pushdown(int id){
            if(tree[id].lazy!=0){
                getnew(id<<1,tree[id].lazy);
                getnew(id<<1|1,tree[id].lazy);
                tree[id].lazy=0;
            }
        }
        void change(int l,int r,int id,int x){
            if(l==r){
                tree[id].num=1;
                return;
            }
            int mid=(l+r)>>1;
            if(x<=mid) change(l,mid,id<<1,x);
            else change(mid+1,r,id<<1|1,x);
            tree[id]=tree[id<<1]+tree[id<<1|1];
        }
        void update(int l,int r,int id,int tl,int tr,int val){
            if(r<tl || tr<l) return;
            if(tl<=l && r<=tr){
                getnew(id,val);
                return;
            }
            pushdown(id);
            int mid=(l+r)>>1;
            update(l,mid,id<<1,tl,tr,val);update(mid+1,r,id<<1|1,tl,tr,val);
            tree[id]=tree[id<<1]+tree[id<<1|1];
        }
    }Segtree;
    long long res[maxn];
    void solve(){
        for(int i=1;i<=4*n;i++) Segtree.tree[i]=node();
        vector<int> Min,Max;
        for(int i=1;i<=n;i++){
            int x=p[i];
            while(!Min.empty() && p[Min.back()]>x){
                int pos=Min.back();Min.pop_back();
                if(Min.empty()) Segtree.update(1,n,1,1,pos,p[pos]-x);
                else Segtree.update(1,n,1,Min.back()+1,pos,p[pos]-x);
            }
            while(!Max.empty() && p[Max.back()]<x){
                int pos=Max.back();Max.pop_back();
                if(Max.empty()) Segtree.update(1,n,1,1,pos,x-p[pos]);
                else Segtree.update(1,n,1,Max.back()+1,pos,x-p[pos]);
            }
            Min.push_back(i);Max.push_back(i);
            if(i>1) Segtree.update(1,n,1,1,i-1,-1);
            Segtree.change(1,n,1,i);
            res[i]=res[i-1]+Segtree.tree[1].num;
        }
    }
}
namespace Solve_right{
    struct DSU{
        int par[maxn],r[maxn];
        long long cnt=0;
        void init(){
            cnt=0;
            for(int i=0;i<=n+1;i++) par[i]=r[i]=0;
        }
        int findpar(int u){
            if(u!=par[u]) return par[u]=findpar(par[u]);
            return u;
        }
        void unions(int u,int v){
            u=findpar(u);v=findpar(v);
            if(r[u]<r[v]) swap(v,u);
            cnt+=1LL*r[u]*r[v];
            par[v]=u;r[u]+=r[v];
        }
        void get(int x){
            par[x]=x;r[x]=1;cnt++;
            if(par[x] && par[x-1]) unions(x,x-1);
            if(par[x] && par[x+1]) unions(x,x+1);
        }
    }dsu;
    long long res[maxn];
    void solve(){
        dsu.init();
        for(int i=0;i<=n+1;i++) res[i]=0;
        for(int i=n;i>=1;i--){
            dsu.get(p[i]);
            res[i]=dsu.cnt;
        }
    }
}
namespace Solve_merge{
    struct BIT{
        int up[maxn],down[maxn],bit[maxn];
        void build(){
            for(int i=1;i<=n;i++){up[i]=n+1;down[i]=0;bit[i]=0;}
        }
        void update(int x){
            for(int i=x;i<=n;i+=(i&(-i))){
                down[i]=max(down[i],x);
                bit[i]++;
            }
            for(int i=n-x+1;i<=n;i+=(i&(-i))) up[i]=min(up[i],x);
        }
        int query(int x){
            int res=0;
            for(int i=x;i>=1;i-=(i&(-i))) res+=bit[i];
            return res;
        }
        int query_range(int l,int r){
            return query(r)-query(l-1);
        }
        int query_up(int x){
            int res=n+1;
            for(int i=n-x;i>=1;i-=(i&(-i))) res=min(res,up[i]);
            return res;
        }
        int query_down(int x){
            int res=0;
            for(int i=x-1;i>=1;i-=(i&(-i))) res=max(res,down[i]);
            return res;
        }
    }Bit;
    struct Sparse_table{
        int Min[maxn][maxl],Max[maxn][maxl],lg2[maxn];
        int query_Max(int l,int r){
            int p=lg2[r-l+1];
            return max(Max[l][p],Max[r-(1<<p)+1][p]);
        }
        int query_Min(int l,int r){
            int p=lg2[r-l+1];
            return min(Min[l][p],Min[r-(1<<p)+1][p]);
        }
        void build(){
            for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
            for(int i=1;i<=n;i++) Max[i][0]=Min[i][0]=p[i];
            for(int i=1;i<=20;i++){
                for(int j=1;j<=(n-(1<<i)+1);j++){
                    Max[j][i]=max(Max[j][i-1],Max[j+(1<<(i-1))][i-1]);
                    Min[j][i]=min(Min[j][i-1],Min[j+(1<<(i-1))][i-1]);
                }
            }
        }
    }Sparse;
    struct state{
        int pos=0,num=0,Max=0,cnt=0,cur=0;
        state(){}
    };
    struct node{
        state pMin,sMin,pMax,sMax;
        bool okMin=true,okMax=true;
        long long total=0;
        node(){}
        friend node operator+(node a,node b){
            if(b.pMin.pos==0) return a;
            node res;
            res.pMin=a.pMin;res.pMax=a.pMax;
            res.sMin=b.sMin;res.sMax=b.sMax;
            res.total=a.total+b.total;
            res.okMin=res.okMax=false;
            if(a.sMin.num==b.pMin.num){
                int dMax=Sparse.query_Max(a.sMin.pos,b.pMin.pos-1),dMin=Sparse.query_Min(a.sMin.pos,b.pMin.pos-1),d=b.pMax.num;
                int nwMax=max(a.sMin.Max,b.pMin.Max);
                res.total-=1LL*(a.sMin.Max+b.pMin.Max)*a.sMin.cur;
                if(dMin==d+1 && dMax-dMin+1==b.pMin.pos-a.sMin.pos){
                    res.okMin=(a.okMin && b.okMin);
                    nwMax=max(nwMax,a.sMin.cnt+b.pMin.cnt);
                    res.pMin.cnt+=a.okMin*b.pMin.cnt;
                    res.sMin.cnt+=b.okMin*a.sMin.cnt;
                }
                else if(dMax-dMin+1==b.pMin.pos-a.sMin.pos){
                    nwMax=max(nwMax,a.sMin.cnt+1);
                    res.pMin.cnt+=a.okMin;
                }
                res.total+=1LL*nwMax*a.sMin.cur;
                if(a.pMin.num==a.sMin.num) res.pMin.Max=nwMax;
                if(b.pMin.num==b.sMin.num) res.sMin.Max=nwMax;
            }
            if(a.sMax.num==b.pMax.num){
                int dMax=Sparse.query_Max(a.sMax.pos,b.pMax.pos-1),dMin=Sparse.query_Min(a.sMax.pos,b.pMax.pos-1),d=b.pMin.num;
                int nwMax=max(a.sMax.Max,b.pMax.Max);
                res.total-=1LL*(a.sMax.Max+b.pMax.Max)*a.sMax.cur;
                if(dMax==d-1 && dMax-dMin+1==b.pMax.pos-a.sMax.pos){
                    res.okMax=(a.okMax && b.okMax);
                    nwMax=max(nwMax,a.sMax.cnt+b.pMax.cnt);
                    res.pMax.cnt+=a.okMax*b.pMax.cnt;
                    res.sMax.cnt+=b.okMax*a.sMax.cnt;
                }
                else if(dMax-dMin+1==b.pMax.pos-a.sMax.pos){
                    nwMax=max(nwMax,a.sMax.cnt+1);
                    res.pMax.cnt+=a.okMax;
                }
                res.total+=1LL*nwMax*a.sMax.cur;
                if(a.pMax.num==a.sMax.num) res.pMax.Max=nwMax;
                if(b.pMax.num==b.sMax.num) res.sMax.Max=nwMax;
            }
            return res;
        }
    };
    struct ST{
        node tree[4*maxn];
        void getnew_Max(int id,int num,int cur){
            tree[id].total-=1LL*tree[id].pMax.Max*tree[id].pMax.cur;
            tree[id].pMax.num=tree[id].sMax.num=num;
            tree[id].pMax.cur=tree[id].sMax.cur=cur;
            tree[id].total+=1LL*tree[id].pMax.Max*tree[id].pMax.cur;
        }
        void getnew_Min(int id,int num,int cur){
            //cout << "getnew_Min " << id << ' ' << tree[id].pMin.cur << '\n';
            tree[id].total-=1LL*tree[id].pMin.Max*tree[id].pMin.cur;
            tree[id].pMin.num=tree[id].sMin.num=num;
            tree[id].pMin.cur=tree[id].sMin.cur=cur;
            tree[id].total+=1LL*tree[id].pMin.Max*tree[id].pMin.cur;
        }
        void pushdown(int id){
            if(tree[id].pMin.num==tree[id].sMin.num && tree[id<<1].pMin.num!=tree[id].pMin.num){
                getnew_Min(id<<1,tree[id].pMin.num,tree[id].pMin.cur);
                getnew_Min(id<<1|1,tree[id].pMin.num,tree[id].pMin.cur);
            }
            if(tree[id].pMax.num==tree[id].sMax.num && tree[id<<1].pMax.num!=tree[id].pMax.num){
                getnew_Max(id<<1,tree[id].pMax.num,tree[id].pMax.cur);
                getnew_Max(id<<1|1,tree[id].pMax.num,tree[id].pMax.cur);
            }
        }
        void update_Max(int l,int r,int id,int tl,int tr,int num,int cur){
 
            if(tr<l || r<tl) return;
            if(tl<=l && r<=tr){
                //cout << tree[id].total << ' ' << num << ' ' << cur << '\n';
                getnew_Max(id,num,cur);
                //cout << "Max* " << tl << ' ' << tr << ' ' << l << ' ' << r << ' ' << tree[id].total << '\n';
                return;
            }
            pushdown(id);
            int mid=(l+r)>>1;
            update_Max(l,mid,id<<1,tl,tr,num,cur);update_Max(mid+1,r,id<<1|1,tl,tr,num,cur);
            tree[id]=tree[id<<1]+tree[id<<1|1];
            //cout << "Max " << l << ' ' << r << ' ' << tree[id].total << '\n';
        }
        void update_Min(int l,int r,int id,int tl,int tr,int num,int cur){
            //if(id==1) cout << "Min** " << tl << ' ' << tr << ' ' << num << ' ' << cur << '\n';
            if(tr<l || r<tl) return;
            if(tl<=l && r<=tr){
                //cout << tree[id].total << ' ' << num << ' ' << cur << '\n';
                getnew_Min(id,num,cur);
                //cout << "Min* " << tl << ' ' << tr << ' ' << l << ' ' << r << ' ' << tree[id].total << '\n';
                return;
            }
            pushdown(id);
            int mid=(l+r)>>1;
            update_Min(l,mid,id<<1,tl,tr,num,cur);update_Min(mid+1,r,id<<1|1,tl,tr,num,cur);
            tree[id]=tree[id<<1]+tree[id<<1|1];
            //cout << "Min " << l << ' ' << r << ' ' << tree[id].total << '\n';
        }
        void change(int l,int r,int id,int p,int pos,int num,int curMin,int curMax){
            if(l==r){
                if(num==0) tree[id]=node();
                else{
                    tree[id].pMin.pos=tree[id].pMax.pos=pos;
                    tree[id].pMin.num=tree[id].pMax.num=num;
                    tree[id].pMin.cur=curMin;tree[id].pMax.cur=curMax;
                    tree[id].pMin.Max=tree[id].pMax.Max=tree[id].pMin.cnt=tree[id].pMax.cnt=1;
                    tree[id].total=curMin+curMax;
                    tree[id].sMin=tree[id].pMin;tree[id].sMax=tree[id].pMax;
                }
                return;
            }
            pushdown(id);
            int mid=(l+r)>>1;
            if(p<=mid) change(l,mid,id<<1,p,pos,num,curMin,curMax);
            else change(mid+1,r,id<<1|1,p,pos,num,curMin,curMax);
            tree[id]=tree[id<<1]+tree[id<<1|1];
            //cout << "Change " << mid+1 << ' ' << r << ' ' << tree[id<<1|1].total << ' ' << tree[id<<1|1].pMax.pos << ' ' << tree[id<<1|1].pMax.num << ' ' << tree[id<<1|1].pMax.cnt << '\n';
            //cout << "Change " << l << ' ' << mid << ' ' << tree[id<<1].total << ' ' << tree[id<<1].sMax.pos << ' ' << tree[id<<1].sMax.num << ' ' << tree[id<<1].sMax.cnt << '\n';
        }
    }Segtree;
    long long res[maxn];
    int st[maxn],sz;
    void solve(){
        sz=0;
        for(int i=1;i<=4*n;i++) Segtree.tree[i]=node();
        Bit.build();
        Sparse.build();
        vector<pii> Min,Max;
        for(int i=1;i<=n;i++){
            //cout << i << '\n';
            int x=p[i],val_up=Bit.query_up(x)-x-1,val_down=x-Bit.query_down(x)-1;
            //cout << val_up << ' ' << val_down << '\n';
            while(sz && Bit.query_range(Sparse.query_Min(st[sz],i),Sparse.query_Max(st[sz],i))!=i-st[sz]){
                //cout << st[sz] << ' ' << Sparse.query_Min(st[sz],i) << ' ' << Sparse.query_Max(st[sz],i) << '\n';
                Segtree.change(1,n,1,sz--,0,0,0,0);
            }
            while((int)Min.size()>=2 && Min[(int)Min.size()-2].se>=sz) Min.pop_back();
            if(!Min.empty() && Min.back().se>=sz) Min.back().se=sz;
            while((int)Max.size()>=2 && Max[(int)Max.size()-2].se>=sz) Max.pop_back();
            if(!Max.empty() && Max.back().se>=sz) Max.back().se=sz;
            while(!Min.empty() && Min.back().fi>x){
                int pos=Min.back().se;Min.pop_back();
                if(Min.empty()) Segtree.update_Min(1,n,1,1,pos,x,val_down);
                else Segtree.update_Min(1,n,1,Min.back().se+1,pos,x,val_down);
            }
            while(!Max.empty() && Max.back().fi<x){
                int pos=Max.back().se;Max.pop_back();
                if(Max.empty()) Segtree.update_Max(1,n,1,1,pos,x,val_up);
                else Segtree.update_Max(1,n,1,Max.back().se+1,pos,x,val_up);
            }
            Segtree.change(1,n,1,++sz,i,x,val_down,val_up);st[sz]=i;
            Min.push_back({p[i],sz});Max.push_back({p[i],sz});
            Bit.update(x);
            res[i]=Segtree.tree[1].total+sz;
            /*
            cout << sz << ' ' << res[i] << ' ' << val_up << ' ' << val_down << '\n';
            cout << "vector<Min>\n";
            for(pii a:Min) cout << '{' << a.fi << ',' << a.se << '}' << ' ';
            cout << '\n';
            cout << "vector<Max>\n";
            for(pii a:Max) cout << '{' << a.fi << ',' << a.se << '}' << ' ';
            cout << '\n';
            */
 
        }
        //cout << '\n';
    }
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    Solve_left::solve();
    Solve_right::solve();
    Solve_merge::solve();
    cout << 1LL*n*(n+1)/2 << ' ';
    for(int i=1;i<=n;i++) cout << Solve_left::res[i-1]+Solve_right::res[i+1]+Solve_merge::res[i] << ' ';
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test=1;cin >> test;
    while(test--) solve();
}
 
