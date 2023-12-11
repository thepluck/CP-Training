#include <bits/stdc++.h>

using namespace std;
const long long maxN = 501;

long long m, n;
long long c[maxN][maxN];
long long s[maxN];
long long myAns, yourAns;

double Check(string inp, string out, string ans) {
    // ans --> hoc sinh
    // out --> me
    FILE *fileInput = fopen(inp.c_str(), "r");
    FILE *fileOut = fopen(out.c_str(), "r");
    FILE *fileAns = fopen(ans.c_str(), "r");
    
    long long isOk = 1;
    
    fscanf(fileInput, "%lld %lld", &n, &m);

    for (long long i=1; i<=n; i++) {
        fscanf(fileInput, "%lld", &s[i]);
    }

    for (long long i=0; i<=n; i++) {
        for (long long j=0; j<=n; j++)
            fscanf(fileInput, "%lld", &c[i][j]);
    }

    fclose(fileInput);
         

    // Get my ans
    myAns = 0;
    long long dd[maxN];
    long long sum, li;
    memset(dd,0,sizeof(dd));


    for (long long i=1; i<=m; i++) {
    	long long k, p;
    	sum = 0;
    	fscanf(fileOut, "%lld", &k);
        for (long long j=1; j<=k; j++) {
        	fscanf(fileOut, "%lld", &p);
        	sum += s[p];
        	dd[p] = 1;
        }

        myAns = max(myAns, sum);
    }

    fclose(fileOut);

    sum = 0;
    li = 0;
    for (long long i=1; i<=n; i++) 
    	if (dd[i] == 0) {
    		sum += c[li][i];
    		li = i;
    	}
    sum += c[li][0];
    myAns = max(myAns, sum);


    // Get your ans
    yourAns = 0;
    memset(dd,0,sizeof(dd));

    for (long long i=1; i<=m; i++) {
    	long long k, p;
    	sum = 0;
    	fscanf(fileAns, "%lld", &k);

    	if ((k < 0) || (k > n)) {    
            fclose(fileAns);
            return -1;
        }

        for (long long j=1; j<=k; j++) {
        	fscanf(fileAns, "%lld", &p);

        	if ((p < 1) || (p > n) || (dd[p] == 1)) {    
	            fclose(fileAns);
	            return -2;
        	}

        	sum += s[p];
        	dd[p] = 1;
        }

        yourAns = max(yourAns, sum);
    }

    sum = 0;
    li = 0;
    for (long long i=1; i<=n; i++) 
    	if (dd[i] == 0) {
    		sum += c[li][i];
    		if (i - li > 3) {    
	            fclose(fileAns);
	            return -3;
        	}
            li = i;
    	}

    if (n+1 - li > 3) {    
        fclose(fileAns);
        return -4;
	}

    sum += c[li][0];
    yourAns = max(yourAns, sum);

    fclose(fileAns);

    if (yourAns * 10 > 11*myAns) return -5;

    double p = (yourAns - myAns) * 1.0 / myAns;

    if (p <= 1e-9) return 1;

    return -log(p+0.0001) / log(10) * 0.25;
}

int main(int argc, const char *argv[]) {
	string inp(argv[1]);
	string out(argv[2]);
	string ans(argv[3]);
    double result = Check(inp, out, ans);
    cout << setprecision(10) << fixed;
    if (result < 0) cout << "Wrong answer\n";
    else cout << "Partial result: " << result << " points\n";

}
