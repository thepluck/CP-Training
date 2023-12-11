#include <bits/stdc++.h>
using namespace std;

struct lr{
	long l, r;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector < vector <int> > v (n, vector <int> (m));
	vector < vector <int> > len (n, vector <int> (m));
	for (int i = 0; i < m; i++){
		cin >> v[0][i];
		len[0][i] = v[0][i];
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> v[i][j];
			if (v[i][j]) len[i][j] = len[i - 1][j] + 1;
			else len[i][j] = 0;
		}
	int area = 0;
	for (int i = 0; i < n; i++){
		vector <lr> pos(m); 
		stack <int> dl, dr;
		dl.push(-1); dr.push(m);
		for (int j = 0; j < m; j++){
			while (dl.top() != -1 && len[i][dl.top()] >= len[i][j]) dl.pop();
			pos[j].l = dl.top() + 1;
			dl.push(j);
		}
		for (int j = m - 1; j >= 0; j--){
			while (dr.top() != m && len[i][dr.top()] >= len[i][j]) dr.pop();
			pos[j].r = dr.top() - 1;
			dr.push(j);
			}
		int temp;
		for (int j = 0; j < m; j++){
			temp = (pos[j].r - pos[j].l + 1) * len[i][j];
			if (temp > area) area = temp;
		}
	}
	cout << area << '\n';
	return 0;
}
