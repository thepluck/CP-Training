#define first fi
#define second se
#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > ii;
const int MAX=1002,inf=(1e9);
int num,n;
char c[MAX][MAX];
bool a[MAX][MAX],th[MAX][MAX];
int s[MAX*100],b[MAX][MAX];
//pair < int, int >
int z=0;
ii p;
int X[]={0,0,1,-1},Y[]={1,-1,0,0};
void BFS(int u,int v)
{
    queue < ii > q;
    q.push(ii(u,v));
    s[z]=1;
    b[u][v]=z;
    th[u][v]=1;

    while( !q.empty())
    {
        p=q.front();
        //cout<<p.fi<<' '<<p.se;
        //exit(0);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.fi+X[i];
            int y=p.se+Y[i];
            if(!th[x][y] && !a[x][y])
            {
                //cout<<x<<' '<<y;
                //if(y<0) exit(0);
                th[x][y]=1;
                q.push(ii(x,y));
                b[x][y]=z;
                s[z]++;
            }
        }
    }
}
int main()
{
    memset(th,0,sizeof th);
    memset(b,0,sizeof b);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
            {
                cin>>c[i][j];
                a[i][j]=c[i][j]-'0';
            }
        }

    for(int i=2;i<m;i++){
        for(int j=2;j<n;j++)
        {
            if(!th[i][j] && !a[i][j])
            {
                z++;
                BFS(i,j);
            }
        }
    }
    //return 0;
    int res=0;
    int CH[4];
    for(int i=2;i<m;i++){
        for(int j=2;j<n;j++)
        {
            if(a[i][j])
            {
                int S=1;
                for(int k=0;k<4;k++)
                {
                    CH[k]=0;
                    int x=i+X[k],y=j+Y[k];
                    if(!a[x][y])
                    {
                        int l=0;
                        for(;l<k;l++)
                        {
                            if(b[x][y]==CH[l]) break;
                        }
                        if(l==k) {S+=s[b[x][y]];CH[k]=b[x][y];}
                    }
                }
                res=max(res,S);
            }
        }
    }
    cout<<res;
}