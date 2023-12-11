#include "matching.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <tuple>

using namespace std;

const int MOD = 998244353;
// int add(int a, int b) { return a -= ((a += b) >= MOD ? MOD : 0); }
// int sub(int a, int b) { return a += ((a -= b) < 0 ? MOD : 0); }
int& inc(int& a, int b) { return a -= ((a += b) >= MOD ? MOD : 0); }
// int& dec(int& a, int b) { return a += ((a -= b) < 0 ? MOD : 0); }
int& mul_two(int& a) { return a -= ((a <<= 1) >= MOD ? MOD : 0); }

int count_matching(int N, int M, int A, int B, std::vector<int> U, std::vector<int> V) {
	vector<char> conn_a(N, 0), conn_b(N, 0);
	for (int i = 0; i < M; ++i) {
		--U[i], --V[i];
		if (V[i] - U[i] == A) conn_a[V[i]] = 1;
		else conn_b[V[i]] = 1;
	}

	if (B <= 20) {
		vector<int> cur(1 << B, 0), nxt(1 << B, 0);
		cur[0] = 1;
		int all_mask = (1 << B) - 1;
		for (int i = 0; i < N; ++i) {
			fill(nxt.begin(), nxt.end(), 0);
			for (int mask = 0; mask < (1 << B); ++mask) if (cur[mask]) {
				inc(nxt[((mask << 1) | 1) & all_mask], cur[mask]);
				if (conn_b[i] && ((mask >> (B - 1)) & 1)) inc(nxt[(mask << 1) & all_mask], cur[mask]);
				if (conn_a[i] && ((mask >> (A - 1)) & 1)) inc(nxt[((mask << 1) ^ (1 << A)) & all_mask], cur[mask]);
			}
			cur.swap(nxt);
			// for (int mask = 0; mask < (1 << B); ++mask) {
			// 	if (cur[mask]) cout << i + 1 << ' ' << bitset<20>(mask) << ": " << cur[mask] << endl;
			// }
		}
		int ans = 0;
		for (int mask = 0; mask < (1 << B); ++mask) {
			inc(ans, cur[mask]);
		}
		return ans;
	} else {
		int G = __gcd(A, B);
		long long final_ans = 1;

		for (int offset = 0; offset < G; ++offset) {
			int D = B / __gcd(A, B); // D >= 2
			vector<pair<int, int>> vec;
			vector<int> min_b(D, N), max_b(D, -N);
			for (int a = 0; a < D; ++a) {
				for (int b = -N; b < N; ++b) if (0 <= a * A + b * B && a * A + b * B < N) {
					min_b[a] = min(min_b[a], b);
					max_b[a] = max(max_b[a], b);
					if (a > 1) vec.emplace_back(a, b);
				}
			}
			sort(vec.begin(), vec.end());

			int head_len = (N - 1) / B + 1;
			int sec_len = (N - A - 1) / B + 1;

			vector<int> init_cur(1 << (head_len + sec_len), 0), init_nxt(1 << (head_len + sec_len), 0);
			init_cur[1] = 1;
			for (int b = 1; b < head_len; ++b) {
				fill(init_nxt.begin(), init_nxt.end(), 0);
				for (int mask = 0; mask < (1 << (head_len + sec_len)); ++mask) if (init_cur[mask]) {
					inc(init_nxt[mask ^ (1 << b)], init_cur[mask]);
					if (conn_b[b * B] && ((mask >> (b - 1)) & 1)) inc(init_nxt[mask ^ (1 << (b - 1))], init_cur[mask]);
				}
				init_cur.swap(init_nxt);
			}
			for (int b = 0; b < sec_len; ++b) {
				fill(init_nxt.begin(), init_nxt.end(), 0);
				for (int mask = 0; mask < (1 << (head_len + sec_len)); ++mask) if (init_cur[mask]) {
					inc(init_nxt[mask ^ (1 << (head_len + b))], init_cur[mask]);
					if (b > 0 && conn_b[A + b * B] && ((mask >> (head_len + b - 1)) & 1)) inc(init_nxt[mask ^ (1 << (head_len + b - 1))], init_cur[mask]);
					if (conn_a[A + b * B] && ((mask >> b) & 1)) inc(init_nxt[mask ^ (1 << b)], init_cur[mask]);
				}
				init_cur.swap(init_nxt);
			}


			int ans = 0;
			assert(min_b[0] == 0);
			assert(min_b[1] == 0);
			assert(sec_len == max_b[1] - min_b[1] + 1);
			for (int head_mask = 0; head_mask < (1 << head_len); ++head_mask) {
				// cout << endl;
				// cout << "head = " << bitset<20>(head_mask) << endl;

				vector<int> cur(1 << sec_len, 0), nxt(1 << sec_len, 0);
				for (int mask = 0; mask < (1 << sec_len); ++mask) {
					cur[mask] = init_cur[(mask << head_len) | head_mask];
				}

				for (auto p : vec) {
					int a, b, i;
					tie(a, b) = p;
					i = a * A + b * B;
					// cout << "a = " << a << ", b = " << b << ", i = " << i << endl;

					int cur_len = max_b[a] - min_b[a] + 1;
					if (min_b[a] == b) {
						int prv_len = max_b[a - 1] - min_b[a - 1] + 1;
						nxt.assign(1 << cur_len, 0);
						for (int mask = 0; mask < (1 << prv_len); ++mask) if (cur[mask]) {
							int nmask = mask;
							if (min_b[a] < min_b[a - 1]) nmask <<= (min_b[a - 1] - min_b[a]);
							else nmask >>= (min_b[a] - min_b[a - 1]);
							nmask &= (1 << cur_len) - 1;
							inc(nxt[nmask], cur[mask]);
						}
						cur.swap(nxt);
						nxt.resize(1 << cur_len);
					}

					fill(nxt.begin(), nxt.end(), 0);
					int r = b - min_b[a];
					for (int prv_mask = 0; prv_mask < (1 << cur_len); ++prv_mask) if (cur[prv_mask]) {
						int cur_mask = prv_mask;
						if ((cur_mask >> r) & 1) cur_mask ^= (1 << r);
						
						inc(nxt[cur_mask | (1 << r)], cur[prv_mask]);
						if (r > 0 && conn_b[i] && ((prv_mask >> (r - 1)) & 1)) inc(nxt[cur_mask ^ (1 << (r - 1))], cur[prv_mask]);
						if (conn_a[i] && ((prv_mask >> r) & 1)) inc(nxt[cur_mask], cur[prv_mask]);
					}
					cur.swap(nxt);

					// for (int cur_mask = 0; cur_mask < (1 << cur_len); ++cur_mask) if (cur[cur_mask]) {
						// cout << bitset<20>(cur_mask) << ": " << cur[cur_mask] << endl;
					// }
				}

				int last_a = (vec.empty() ? 1 : vec.back().first);
				for (int tail_mask = 0; tail_mask < (int) cur.size(); ++tail_mask) if (cur[tail_mask]) {
					int tmp = cur[tail_mask];
					// cout << "tmp = " << tmp << endl;
					if (last_a == D - 1) {
						for (int b = min_b[D - 1]; D * A + b * B < N; ++b) {
							if (conn_a[D * A + b * B] && ((tail_mask >> (b - min_b[D - 1])) & 1) && ((head_mask >> (b + D * A / B)) & 1)) {
								mul_two(tmp);
							}
						}
					}
					inc(ans, tmp);
				}
				// cout << "ans = " << ans << endl;
			}
			// cout << "Ans = " << ans << endl;

			final_ans = final_ans * ans % MOD;
			conn_a.erase(conn_a.begin());
			conn_b.erase(conn_b.begin());
			--N;
		}
		return (int) final_ans;
	}

	assert(false);
	return 0;
}