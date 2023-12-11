#include <bits/stdc++.h>
using namespace std;
int n;
class point_t{
public:
    int x, y;
    point_t(){}
    point_t(int x, int y): x(x), y(y){}
};
point_t p[100000];
double f[100000];
double get_a(double a){
    for(int i=0; i<n; i++) f[i]=a*p[i].x-p[i].y;
    nth_element(f, f+n/2, f+n);//this is actually O(n) on average
    double best_b=f[n/2];
    double res=0;
    for(int i=0; i<n; i++) res+=abs(f[i]-best_b);
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    double low=-2e6, high=2e6, llh, lhh;
    for(int i=0; i<100; i++){
        llh=(low+low+high)/3;
        lhh=(low+high+high)/3;
        double l=get_a(llh);
        double r=get_a(lhh);
        if(l<r) high=lhh;
        else low=llh;
    }
    cout<<setprecision(8)<<fixed<<get_a((low+high)/2);
}