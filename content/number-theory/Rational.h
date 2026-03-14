/**
 * Author: ChatGPT
 * Date: 2026-03-11
 * License: CC0
 * Source: N/A
 * Description: a struct for rational numbers
 * */
struct Rat {
  ll a, b; // a / b
  Rat(ll a = 0, ll b = 1) : a(a), b(b) { norm(); }
  void norm() {
    if (a == 0) { b = 1; return; }
    if (b < 0) a = -a, b = -b;
    ll g = gcd(a < 0 ? -a : a, b);
    a /= g; b /= g;
  }
  Rat operator-() const { return Rat(-a, b); }
  Rat& operator+=(const Rat& o) {
    a = a * o.b + o.a * b;
    b = b * o.b;
    norm();
    return *this;
  }
  Rat& operator-=(const Rat& o) {
    a = a * o.b - o.a * b;
    b = b * o.b;
    norm();
    return *this;
  }
  Rat& operator*=(const Rat& o) {
    a *= o.a;
    b *= o.b;
    norm();
    return *this;
  }
  Rat& operator/=(const Rat& o) {
    a *= o.b;
    b *= o.a;
    norm();
    return *this;
  }
  friend Rat operator+(Rat x, const Rat& y) { return x += y; }
  friend Rat operator-(Rat x, const Rat& y) { return x -= y; }
  friend Rat operator*(Rat x, const Rat& y) { return x *= y; }
  friend Rat operator/(Rat x, const Rat& y) { return x /= y; }
  friend bool operator==(const Rat& x, const Rat& y) {
    return x.a == y.a && x.b == y.b;
  }
  friend bool operator!=(const Rat& x, const Rat& y) { return !(x == y); }
  friend bool operator<(const Rat& x, const Rat& y) {
    return x.a * y.b < y.a * x.b;
  }
  friend bool operator>(const Rat& x, const Rat& y) { return y < x; }
  friend bool operator<=(const Rat& x, const Rat& y) { return !(y < x); }
  friend bool operator>=(const Rat& x, const Rat& y) { return !(x < y); }
  explicit operator double() const { return (double)a / b; }
  explicit operator long double() const { return (long double)a / b; }
  friend ostream& operator<<(ostream& os, const Rat& x) {
    return os << x.a << '/' << x.b;
  }
};
