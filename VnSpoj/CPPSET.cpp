#include <iostream>
#include <set>
#include <algorithm>
#define lb lower_bound
#define ub upper_bound
using namespace std;

set <int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cmd, x;
	while (cin >> cmd){
		if (cmd == 0) return 0;
		if (cmd != 3 && cmd != 4) cin >> x;
		if (cmd == 1) s.insert(x);
		if (cmd == 2) s.erase(x);
		if (cmd == 3){
			if (s.empty()) cout << "empty\n";
			else cout << *s.begin() << '\n';
		}
		if (cmd == 4){
			if (s.empty()) cout << "empty\n";
			else cout << *s.rbegin() << '\n';
		}
		if (cmd == 5){
			if (s.empty()){
				cout << "empty\n";
			}
			else {
				auto it = s.ub(x);
				if (it == s.end()) cout << "no\n";
				else cout << *it << '\n';
			}
		}
		if (cmd == 6){
			if (s.empty()){
				cout << "empty\n";
			}
			else {
				auto it = s.lb(x);
				if (it == s.end()) cout << "no\n";
				else cout << *it << '\n';
			}
		}
		if (cmd == 7){
			if (s.empty()){
				cout << "empty\n";
			}
			else {
				auto it = s.lb(x);
				if (it == s.begin()) cout << "no\n";
				else cout << *(--it) << '\n';
			}
		}
		if (cmd == 8){
			if (s.empty()){
				cout << "empty\n";
			}
			else {
				auto it = s.ub(x);
				if (it == s.begin()) cout << "no\n";
				else cout << *(--it) << '\n';
			}
		}
	}
	return 0;
}