/**
 * Author: cpalgo
 * Date: 2026-03-11
 * License: CC0
 * Description: Solves a list of congruences iteratively using CRT, might want to use 128-bit integers
 * Status: Works
 */
struct cong { ll a, m; };
ll crt_system(vector<cong>& congs) {
  ll M = 1;
  for (auto &c : congs) M *= c.m;
  ll sol = 0;
  for (auto &c : congs) {
    ll Mi = M / c.m, A, B;
    euclid(Mi, c.m, A, B);
    A = ((A % c.m) + c.m) % c.m;
    sol = (sol + c.a * Mi % M * A) % M;
  }
  return sol;
}
