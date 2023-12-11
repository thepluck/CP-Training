#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "w", stdout);
	srand(time(NULL));

	int n = rand() % 1000 + 1;
	cout << n << '\n';
	for (int i = 1; i <= n; ++i) cout << rand() % 1000 + 1 << " "; 
}