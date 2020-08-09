#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
typedef long long int64;
static const int MAXN = 1004;
#ifndef M_PI
static const double M_PI = acos(-1.0);
#endif

int n;
int x[MAXN], y[MAXN], r[MAXN];
int par[MAXN];
std::vector<int> e[MAXN];

bool level[MAXN];

// Whether one of C[u] and C[v] is contained in another
inline bool circle_contains(int u, int v)
{
    return ((int64)(x[u] - x[v]) * (x[u] - x[v]) + (int64)(y[u] - y[v]) * (y[u] - y[v]) <= (int64)(r[u] - r[v]) * (r[u] - r[v]));
}

void dfs_colour(int u, bool c)
{
    level[u] = c;
    for (int v : e[u]) dfs_colour(v, c ^ 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);

    for (int i = 0; i < n; ++i) {
        par[i] = -1;
        for (int j = 0; j < n; ++j)
            if (r[j] > r[i] && circle_contains(i, j)) {
                if (par[i] == -1 || r[par[i]] > r[j]) par[i] = j;
            }
        e[par[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) if (par[i] == -1) dfs_colour(i, false);
    int64 ans = 0;
    for (int i = 0; i < n; ++i)
        ans += (int64)r[i] * r[i] * (par[i] == -1 || (level[i] == true) ? +1 : -1);
    printf("%.8lf\n", (double)ans * M_PI);

    return 0;
}