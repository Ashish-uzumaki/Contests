int n;
struct rect {
  int x, y, val;
} a[N];
 
bool Q;
struct Line {
  mutable int m, c, p;
  // m slope, c intercept, p line range
  bool operator<(const Line &o) const { return Q ? p < o.p : m < o.m; }
};
 
struct LineContainer : multiset<Line> {
  // (for doubles, use INF = 1/.0, div(a,b) = a/b)
  // taking two consecutive lines updating x
  // and teintng would be in hull or not
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = INF;
      return false;
    }
    if (x->m == y->m)
      x->p = x->c > y->c ? INF : -INF;
    else
      x->p = (y->c - x->c) / (x->m - y->m);
    return x->p >= y->p;
  }
 
  void add(int m, int c) {
    //
    auto z = insert({m, c, 0}), y = z++, x = y;
 
    // checking for lines having slope >= k
    while (isect(y, z))
      z = erase(z);
 
    // checking for current line
    if (x != begin() && isect(--x, y)) {
      y = erase(y);
      isect(x, y);
      y = x;
    }
 
    // checking for lines having slope < k
    while (y != begin() && (--x)->p >= y->p) {
      isect(x, erase(y));
      y = x;
    }
  }
 
  int query(int x) {
    assert(!empty());
    Q = 1; // just to change search operator
    auto l = *lower_bound({0, 0, x});
    Q = 0;
    return l.m * x + l.c;
  }
};