
#include <cstdio>
#include <vector>
using namespace std;

class Trie{
	public :
		class Node{
			public :
				int num, cnt;
				Node* next[2];
				Node(){
					num = cnt = 0;
					next[0] = next[1] = nullptr;
				}
		} *root = new Node();
		void insert(const vector <int>& v){
			Node* pt = root;
			for (int x : v){
				if (pt->next[x] == nullptr)
					pt->next[x] = new Node();
				pt = pt->next[x];
				pt->num++;
			}
			pt->cnt++;
		}
		int match(const vector <int>& v){
			Node* pt = root;
			int ans = 0;
			for (int x : v){
				pt = pt->next[x];
				if (pt == nullptr) break;
				ans += pt->cnt;
			}
			if (pt != nullptr)
				ans += pt->num - pt->cnt;
			return ans;
		}
} T;

int main(){
	int n, m, x;
	vector <int> v;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		v.resize(x);
		for (int i = 0; i < x; i++)
			scanf("%d", &v[i]);
		T.insert(v);
	}
	for (int i = 0; i < m; i++){
		scanf("%d", &x);
		v.resize(x);
		for (int i = 0; i < x; i++)
			scanf("%d", &v[i]);
		printf("%d\n", T.match(v));
	}
	return 0;
}
