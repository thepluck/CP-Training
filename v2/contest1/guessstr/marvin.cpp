/*************************************
*    author: marvinthang             *
*    created: 07.04.2023 09:16:55    *
*************************************/

#include "guessstr.h"
#include <bits/stdc++.h>

using namespace std;

#define                  fi  first
#define                  se  second
#define                left  ___left
#define               right  ___right
#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define             MASK(i)  (1LL << (i))
#define           BIT(x, i)  ((x) >> (i) & 1)
#define  __builtin_popcount  __builtin_popcountll
#define              ALL(v)  (v).begin(), (v).end()
#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define          REPD(i, n)  for (int i = (n); i--; )
#define        FOR(i, a, b)  for (int i = (a), _b = (b); i < _b; ++i) 
#define       FORD(i, b, a)  for (int i = (b), _a = (a); --i >= _a; ) 
#define       FORE(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define      FORDE(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 
#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#ifdef LOCAL
    #include "debug.h"
#else
    #define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
    #define DB(...) 23
    #define db(...) 23
    #define debug(...) 23
#endif

template <class U, class V> scan_op(pair <U, V>)  { return in >> u.first >> u.second; }
template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }
template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }

// end of template

int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(seed); 
// mt19937 rng(23);
template <class T> T rand(T l, T h) { return uniform_int_distribution <T> (l, h) (rng); } 
template <class T> T rand(T h) { return uniform_int_distribution <T> (0, h - 1) (rng); } 

int count_matching(string s, string t) {
    int res = 0;
    REP(i, s.size()) res += s[i] == t[i];
    return res;
}

map <int, int> f[4];
int cf[27][6];
string sf[27], af[6];

int dp(int mask, int turn) {
    if (__builtin_popcount(mask) <= 1) {
        if (mask == 1) return turn > 1;
        return 0;
    }
    if (turn <= 0) return -1;
    if (f[turn].count(mask)) return f[turn][mask];
    FOR(i, 1, 6) {
        int new_mask[7] = {};
        REP(j, 27) if (BIT(mask, j)) new_mask[cf[j][i] - cf[j][0] + 3] ^= MASK(j);
        bool ok = true;
        REP(i, 7) if (dp(new_mask[i], turn - 1) < 0) {
            ok = false;
            break;
        }
        if (ok) return f[turn][mask] = i;
    }
    return f[turn][mask] = -1;
}

int first_state;
bool first;

void init(void) {
    first_state = MASK(27) - 1;
    string ss = "012";
    int c = 0;
    do af[c++] = ss;
    while (next_permutation(ALL(ss)));
    REP(i, 3) REP(j, 3) REP(k, 3) {
        int id = i * 9 + j * 3 + k;
        sf[id] += char('0' + i);
        sf[id] += char('0' + j);
        sf[id] += char('0' + k);
        if (i == j && j == k) first_state ^= MASK(id);
        REP(i, 6) cf[id][i] = count_matching(sf[id], af[i]);
    }
    first_state ^= 1;
    dp(first_state, 3);
}

string guess_string(int A, int B, int C) {
	if (!first) {
		init();
		first = true;
	}
	int N = A + B + C;
	int cnt[3] = {A, B, C};
	int pos[3] = {0, 1, 2};
	sort(pos, pos + 3, [&] (int a, int b) { return cnt[a] < cnt[b]; });
	string s = string(A, '0') + string(B, '1') + string(C, '2');
	shuffle(ALL(s), rng);
	vector <int> List[3];
	REP(i, N) List[s[i] - '0'].push_back(i);
	string res(N, '?');
	int f = count_matching(s);
	if (cnt[pos[2]] == N) return s;
	if (!cnt[pos[0]]) {
		int p = List[pos[1]][0];
		int v = -1;
		vector <int> ask;
		for (int i: List[pos[2]]) {
			swap(s[p], s[i]);
			int add = count_matching(s) - f;
			swap(s[p], s[i]);
			ask.push_back(add);
			if (!add) continue;
			if (add > 0) v = pos[2];
			else v = pos[1];
		}
		res[p] = '0' + v;
		REP(i, ask.size()) res[List[pos[2]][i]] = (!ask[i] ? v : ask[i] > 0 ? pos[1] : pos[2]) + '0';
		p = List[pos[2]][0];
		FOR(_, 1, List[pos[1]].size()) {
			int i = List[pos[1]][_];
			swap(s[p], s[i]);
			int add = count_matching(s) - f;
			swap(s[p], s[i]);
			if (!add) res[i] = res[p];
			else if (add > 0) res[i] = '0' + pos[2];
			else res[i] = '0' + pos[1];
		}
		return res;
	}
	int p[3];
	auto solve = [&] (int t) {
		if (cnt[0] + cnt[1] + cnt[2] == 1) {
			REP(i, 3) if (cnt[i] == 1) res[t] = '0' + i;
			return;
		}
		REP(ask, 3) if (ask != s[t] - '0') {
			int i = p[ask];
			swap(s[i], s[t]);
			int x = count_matching(s) - f - (s[i] == res[i]) + (s[t] == res[i]);
			swap(s[i], s[t]);
			if (!x) res[t] = '0' + '1' + '2' - s[t] - s[i];
			else if (x > 0) res[t] = s[i];
			else res[t] = s[t];
			--cnt[res[t] - '0'];
			return;
		}
	};
	int kkk = 0;
	REP(i, List[pos[1]].size()) {
		p[pos[0]] = List[pos[0]][0];
		p[pos[1]] = List[pos[1]][i];
		p[pos[2]] = List[pos[2]][i];

		int mask = first_state;
		FORDE(turn, 3, 1) {
			int ask = dp(mask, turn);
			REP(i, 3) s[p[i]] = af[ask][i];
			int x = count_matching(s) - f;
			++kkk;
			int new_mask = 0;
			REP(j, 27) if (BIT(mask, j) && cf[j][ask] - cf[j][0] == x) new_mask ^= MASK(j);
			mask = new_mask;
			if (__builtin_popcount(mask) == 1) break;
		}
		REP(i, 3) s[p[i]] = char('0' + i);
		if (mask > 1) {
			int t = __builtin_ctz(mask);
			REP(i, 3) res[p[i]] = sf[t][i];
			REP(j, i) res[List[pos[1]][j]] = res[List[pos[2]][j]] = res[p[pos[0]]];
			REP(i, N) if (res[i] != '?') --cnt[res[i] - '0'];
			REP(_, 3) FOR(j, _ ? i + 1 : 1, List[pos[_]].size()) solve(List[pos[_]][j]);
			return res;
		}
	}
	res[List[pos[0]][0]] = '0' + pos[2];
	REP(i, List[pos[1]].size()) res[List[pos[1]][i]] = res[List[pos[2]][i]] = '0' + pos[2];
	REP(i, N) if (res[i] != '?') --cnt[res[i] - '0'];
	FOR(j, List[pos[1]].size(), List[pos[2]].size()) solve(List[pos[2]][j]);
	FOR(i, 1, List[pos[0]].size()) solve(List[pos[0]][i]);
	return res;
}

#ifdef LOCAL
int N, A, B, C;
string S;
int count_ask = 0;

int count_matching(string T) {
  count_ask++;
  int matching = 0;
  for (int i = 0; i < N; i++) {
    matching += S[i] == T[i];
  }
  return matching;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  file("guessstr");
  cin >> N;
  // cin >> S;
  // cout << seed << '\n';
  REP(i, N) S += rand('0', '2');
  for (int i = 0; i < N; i++) {
    A += S[i] == '0';
    B += S[i] == '1';
    C += S[i] == '2';
  }
  string res = guess_string(A, B, C);
  cout << string(20, '=') << '\n';
  cout << "contestant = " << res << '\n';
  cout << "count_ask = " << count_ask << '\n';
  if (res != S) cout << "WRONG ANSWER";
  else cout << "ACCEPTED";
}
#endif
