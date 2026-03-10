/**
 * Author: Lukas Polacek
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */
#pragma once

#include "euclid.h"

const ll mod = 998244353;
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
  Mod() : x(0LL) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator-() { return Mod((mod - x) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * inv(b); }
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
  static Mod inv(Mod a) {
    return a^(mod-2);
  }
	// static Mod inv(Mod a) {
	// 	ll x, y, g = euclid(a.x, mod, x, y);
	// 	assert(g == 1); return Mod((x + mod) % mod);
	// }
	bool operator==(Mod b) const { return x == b.x; }
	bool operator!=(Mod b) const { return x != b.x; }
  bool operator==(ll v) const { return x == (v % mod + mod) % mod; }
  bool operator!=(ll v) const { return !(*this == v); }
};
