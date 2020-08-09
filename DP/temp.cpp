#include "bits/stdc++.h"
using namespace std;

bool cmp( pair<int, int> a, pair<int, int> b )
{
        if( a.first == b.first ) return  a.second > b.second ;
        else return a.first < b.first;
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t--) {
                int n;
                scanf("%d", &n);
                vector< pair<int, int> > dolls;
                for(int i = 0; i < n; i++) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        dolls.push_back(make_pair(x, y));
                }

                sort( dolls.begin(), dolls.end(), cmp );

                vector< pair<int, int> > v;
                v.push_back( dolls[n - 1] );

                for(int i = n - 2; i >= 0; i--) {

                        int lo = 0, hi = v.size() - 1, mid;

                        while(lo <= hi) {
                                mid = (hi + lo) / 2;
                                if(v[mid].fi < dolls[i].fi )
                                        lo = mid + 1;
                                else hi = mid - 1;
                        }

                        if( lo >= v.size() ) v.push_back( dolls[i] );
                        else {
                                v[lo].first = dolls[i].first;
                                v[lo].second = dolls[i].second;
                        }
                }
                printf("%d\n", (int) v.size() );

        }

        return 0;
}