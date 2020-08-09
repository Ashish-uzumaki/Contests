//#define NDEBUG
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace n91 {

using i8 = std::int_fast8_t;
using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u8 = std::uint_fast8_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

struct rep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { ++i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr rep(const usize f, const usize l) noexcept
      : f(std::min(f, l)), l(l) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
struct revrep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { --i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr revrep(const usize f, const usize l) noexcept
      : f(l - 1), l(std::min(f, l) - 1) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
template <class T> auto md_vec(const usize n, const T &value) {
  return std::vector<T>(n, value);
}
template <class... Args> auto md_vec(const usize n, Args... args) {
  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> constexpr T difference(const T &a, const T &b) noexcept {
  if (a < b) {
    return b - a;
  } else {
    return a - b;
  }
}
template <class T> void chmin(T &a, const T &b) noexcept {
  if (b < a) {
    a = b;
  }
}
template <class T> void chmax(T &a, const T &b) noexcept {
  if (a < b) {
    a = b;
  }
}
template <class F> class fix_point : private F {
public:
  explicit constexpr fix_point(F &&f) : F(std::forward<F>(f)) {}

  template <class... Args>
  constexpr decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};
template <class F> constexpr decltype(auto) make_fix(F &&f) {
  return fix_point<F>(std::forward<F>(f));
}
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}

} // namespace n91

#include <cassert>
#include <cstdint>
#include <iterator>
#include <vector>

namespace n91 {

class m61_rolling_hash {
private:
  using u64 = std::uint_fast64_t;
  using size_t = std::size_t;

public:
  using value_type = u64;

private:
  static constexpr u64 pow2(const int exp) noexcept {
    return static_cast<u64>(1) << exp;
  }

  static constexpr u64 Mod = (static_cast<u64>(1) << 61) - 1;

  static constexpr u64 multiplies_plus(const u64 l, const u64 r,
                                       const u64 c) noexcept {
    const u64 ld = l % pow2(31);
    const u64 lu = l / pow2(31);
    const u64 rd = r % pow2(31);
    const u64 ru = r / pow2(31);
    const u64 m = ld * ru + lu * rd;
    u64 v = lu * ru * 2 + ld * rd + m % pow2(30) * pow2(31) + m / pow2(30) + c;
    v = v % pow2(61) + v / pow2(61);
    if (v >= Mod) {
      v -= Mod;
    }
    return v;
  }

  std::vector<u64> prefix;
  std::vector<u64> power;

public:
  m61_rolling_hash() = default;
  template <class C>
  explicit m61_rolling_hash(const C &c, const u64 base = 91)
      : prefix(), power() {
    const size_t n = c.size();
    prefix.reserve(n + 1);
    prefix.push_back(0);
    for (size_t i = 0; i != n; ++i) {
      prefix.push_back(multiplies_plus(prefix.back(), base, c[i]));
    }
    power.reserve(n + 1);
    power.push_back(Mod - 1);
    for (size_t i = 0; i != n; ++i) {
      power.push_back(multiplies_plus(power.back(), base, 0));
    }
  }

  u64 get(const size_t first, const size_t last) const noexcept {
    assert(first <= last);
    assert(last < prefix.size());
    return multiplies_plus(prefix[first], power[last - first], prefix[last]);
  }
  u64 operator()(const size_t first, const size_t last) const noexcept {
    assert(first <= last);
    assert(last < prefix.size());
    return get(first, last);
  }
};

} // namespace n91

#include <cstdint>

namespace n91 {

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  using value_type = u64;

  static constexpr u64 mod = Modulus;

private:
  static_assert(mod < static_cast<u64>(1) << 32,
                "Modulus must be less than 2**32");

  u64 v;

  constexpr modint &negate() noexcept {
    if (v != 0)
      v = mod - v;
    return *this;
  }

public:
  constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}
  constexpr u64 &value() noexcept { return v; }
  constexpr const u64 &value() const noexcept { return v; }
  constexpr modint operator+() const noexcept { return modint(*this); }
  constexpr modint operator-() const noexcept { return modint(*this).negate(); }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    v += rhs.v;
    if (v >= mod)
      v -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (v < rhs.v)
      v += mod;
    v -= rhs.v;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    v = v * rhs.v % mod;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = mod - 2;
    while (exp) {
      if (exp % 2 != 0)
        *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr bool operator==(const modint rhs) const noexcept {
    return v == rhs.v;
  }
  constexpr bool operator!=(const modint rhs) const noexcept {
    return v != rhs.v;
  }
};
template <std::uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;

} // namespace n91
#include <utility>

namespace n91 {

template <class T, class U, class Operate = std::multiplies<T>>
constexpr T power(T base, U exp, const Operate &oper = Operate(), T iden = 1) {
  while (exp != 0) {
    if (exp % 2 != 0) {
      iden = oper(iden, base);
    }
    exp /= 2;
    base = oper(base, base);
  }
  return iden;
}

} // namespace n91

#include <utility>

namespace n91 {

template <class T> constexpr T gcd(T m, T n) noexcept {
  while (n != static_cast<T>(0)) {
    m %= n;
    std::swap(m, n);
  }
  return m;
}

template <class T> constexpr T lcm(const T &m, const T &n) noexcept {
  return m / gcd(m, n) * n;
}

} // namespace n91

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

namespace n91 {

void main_() {
  /*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize n = scan<usize>();
  const u64 m = scan<u32>();
  std::vector<u64> a(n);
  for (auto &e : a)
    std::cin >> e;
  u64 cm = 1;
  for (auto &e : a) {
    e /= 2;
    cm = lcm(cm, e);
    if (cm > m) {
      std::cout << 0 << std::endl;
      return;
    }
  }
  for (const auto e : a) {
    if (cm / e % 2 == 0) {
      std::cout << 0 << std::endl;
      return;
    }
  }
  std::cout << (m / cm) - (m / (2 * cm)) << std::endl;
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
