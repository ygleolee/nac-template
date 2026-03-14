/**
 * Author: Leo Lee
 * Date: 2026-03-11
 * License: CC0
 * Description: computes primes <= n and the mobius function in linear time. 
 * Example shows how to compute the multiplicative function $f(p^k) = k$ without a closed form when $p$ divides $q$.
 * Status: stress-tested
 */

#define MAXN 100005
bitset<MAXN> is_comp;
vector<ll> primes;
ll mob[MAXN];
void sieve() {
  mob[1] = 1;
  for (ll q=2; q<MAXN; ++q) {
    if (!is_comp[q]) {
      primes.push_back(q);
      mob[q] = -1;
    }
    for (auto p : primes) {
      ll x = p * q;
      if (x >= MAXN) break;
      is_comp[x] = 1;
      if (q % p == 0) {
        mob[x] = 0;
        break;
      }
      else mob[x] = mob[p] * mob[q];
    }
  }
}
ll fun[MAXN];
ll cnt[MAXN];
void example() {
  fun[1] = 1;
  for (ll q=2; q<MAXN; ++q) {
    if (!is_comp[q]) {
      primes.push_back(q);
      fun[q] = 1;
      cnt[q] = 1;
    }
    for (auto& p : primes) {
      if (p * q >= MAXN) break;
      is_comp[p * q] = 1;
      if (q % p == 0) {
        fun[p * q] = (cnt[q] + 1) * fun[q] / cnt[q];
        cnt[p * q] = cnt[q] + 1;
        break;
      }
      else {
        fun[p * q] = fun[p] * fun[q];
        cnt[p * q] = 1;
      }
    }
  }
}
