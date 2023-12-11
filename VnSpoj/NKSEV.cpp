#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int mod = 1337377;

struct Trie{
	struct Node{
		bool has;
		Node* next[26];
		Node() : has(false){
			for (int i = 0; i < 26; i++)
				next[i] = nullptr;
		}
	} *root = new Node();
	void insert(const string& s){
		Node* pt = root;
		for (auto x : s){
			int t = x - 'a';
			if (pt->next[t] == nullptr)
				pt->next[t] = new Node();
			pt = pt->next[t];
		}
		pt->has = true;
	}
	int solve(const string& s){
		int n = s.size(); int f[n + 1];
		memset(f, 0, sizeof f);
		f[n] = 1;
		for (int i = n - 1; i >= 0; i--){
			Node* pt = root;
			for (int j = i; j < n; j++){
				int t = s[j] - 'a';
				if (pt->next[t] == nullptr)
					break;
				pt = pt->next[t];
				if (pt->has) f[i] += f[j + 1];
			}
			f[i] %= mod;
		}
		return f[0];
	}
} T;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t; int n;
	cin >> s >> n;
	while (n--){
		cin >> t; T.insert(t);
	}
	cout << T.solve(s);
}