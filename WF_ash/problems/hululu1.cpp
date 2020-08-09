
#include<bits/stdc++.h>
 
typedef long long ll;
typedef long double lld;
using namespace std;
 
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define inf 1e9 + 7
#define pii pair<int, int>
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template <typename T>
ostream &operator<<(ostream &out, set<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << "\n" << (i->first) <<  ":"  << (i->second);
    return out;
}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
// #define int ll
 
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};
vector<vector<char>> arr(4004, vector<char>(6004));
vector<vector<int>> dist(4004, vector<int> (6004)), visited(4010, vector<int> (6004));
int n, m;
int32_t main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        arr.resize(4*n+5);
        dist.resize(4*n+5);
        visited.resize(4*n+5);
        for(int i=0;i<4*n+4;i++){
            arr[i].resize(6*m+5);
            dist[i].resize(6*m+5);
            visited[i].resize(6*m+5);
        }
        for (int i = 0; i < 4 * n + 4; i++) {
            for (int j = 0; j < 6 * m + 4; j++) {
                arr[i][j] = '*';
                dist[i][j] = inf;
                visited[i][j] = 0;
            }
        }
        int cur_row = 0;
        int cur_column = 0;
        pii st, ed;
        char cc;
        scanf("%c", &cc);
        while (cur_row <= 4 * n + 2) {
            char c;
            scanf("%c", &c);
            int t = c;
            arr[cur_row][cur_column] = c;
            if (c == 'S') {
                st = {cur_row, cur_column};
            }
            if (c == 'T') {
                ed = {cur_row, cur_column};
            }
            if (t == 10) {
                cur_row++;
                cur_column = 0;
            } else {
                cur_column++;
            }
        }
 
        auto check = [](pii& a) -> int {
            
            int x = a.fi;
            int y = a.se;
            if (arr[x][y] != ' ') return 0;
            auto check2 = [](int w, int e) -> int {
                if (w >= 0 && e >= 0 && w < (4 * n + 4) && e < (6 * m + 4) && arr[w][e] == '+') return 1;
                return 0;
            };
 
            int a1 = x - 1;
            int b1 = y - 1;
            int cnt = 0;
            cnt += check2(a1, b1);
            a1 = x + 1;
            b1 = y + 1;
            cnt += check2(a1, b1);
            // tr(cnt);
            if (cnt == 2) return 1;
 
 
            cnt = 0;
            a1 = x + 1;
            b1 = y - 1;
            cnt += check2(a1, b1);
            a1 = x - 1;
            b1 = y + 1;
            cnt += check2(a1, b1);
            // tr(cnt);
            if (cnt == 2) return 1;
 
            cnt = 0;
            a1 = x;
            b1 = y - 1;
            cnt += check2(a1, b1);
            b1 = y + 3;
            cnt += check2(a1, b1);
            // tr(cnt);
            if (cnt == 2) return 1;
 
            cnt = 0;
            a1 = x;
            b1 = y - 2;
            cnt += check2(a1, b1);
            b1 = y + 2;
            cnt += check2(a1, b1);
            // tr(cnt);
            if (cnt == 2) return 1;
 
            cnt = 0;
            a1 = x;
            b1 = y - 3;
            cnt += check2(a1, b1);
            b1 = y + 1;
            cnt += check2(a1, b1);
            // tr(cnt);
            if (cnt == 2) return 1;
 
            return 0;
 
        };
        deque<pii> q;
        q.push_front(st);
        visited[st.fi][st.se] = 1;
        dist[st.fi][st.se] = 1;
        while (!q.empty()) {
            auto u = q.front();
            if (arr[u.fi][u.se] == 'T') break;
            // tr(u);
            q.pop_front();
            int border = check(u);
            for (int i = 0; i < 4; i++) {
                int x = u.fi + mx[i];
                int y = u.se + my[i];
                if (x >= 0 && y >= 0 && y < (6 * m + 4) && x < (4 * n + 4)  && (arr[x][y] == ' ' || arr[x][y] == 'T')) {
                    visited[x][y] = 1;
                    if (border == 1) {
                        if (dist[x][y] > dist[u.fi][u.se] + 1) {
                            dist[x][y] = dist[u.fi][u.se] + 1;
                            q.push_back({x, y});
                        }
                    } else {
                        if (dist[x][y] > dist[u.fi][u.se]) {
                            dist[x][y] = dist[u.fi][u.se];
                            q.push_front({x, y});
                        }
                    }
                }
            }
        }
        if (visited[ed.fi][ed.se] == 1)
            printf("%d\n", dist[ed.fi][ed.se]);
        else {
            printf("-1\n");
        }
 
    }
}
