#include <bits/stdc++.h>

using namespace std;

int ask(int i) {
	cout << "? " << i << endl;
	int x; cin >> x; return x;
}

void answer(int i) {
    cout << "! " << i << endl;
    exit(0);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	int m = sqrt(n) - 1;
	while (true) {
		int i = 0;
		while (i < n) {
			int x = ask(i + 1);
			if (x < k) {
				i = (i + 1) % n;
				while (ask(i + 1) != k)
					i = (i + 1) % n;
				answer(i + 1);
			}
			i += m;
		}
	}
}