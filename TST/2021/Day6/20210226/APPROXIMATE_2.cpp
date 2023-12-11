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
double get_b(double a, double b){
    double res=0;
    for(int i=0; i<n; i++) res+=abs(a*p[i].x+b-p[i].y);
    return res;
}
double get_a(double a){
    double low=-2e12, high=2e12, llh, lhh;
    for(int i=0; i<120; i++){
        llh=(low+low+high)/3;
        lhh=(low+high+high)/3;
        double l=get_b(a, llh);
        double r=get_b(a, lhh);
        if(l<r) high=lhh;
        else low=llh;
    }
    return get_b(a, (low+high)/2);
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