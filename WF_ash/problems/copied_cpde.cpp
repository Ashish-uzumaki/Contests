#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
long long sum[2100000];
int p[2100000];
long long get(int n)
{
    static long long tmp[2100000];
    for(int i=1;i<=n;i++)tmp[i]=sum[i];
    sort(tmp+1,tmp+n+1); reverse(tmp+1,tmp+n+1);
    long long ret=0;
    for(int i=1;i<=n;i++)ret+=1ll*p[i]/100*tmp[i];
    return ret;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&p[i]);
        int x,a,y,b; long long k;
        scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
        sort(p+1,p+n+1); reverse(p+1,p+n+1);
        for(int i=1;i<=n;i++)sum[i]=0;
        for(int i=1;i<=n;i++)
        {
            if (i%a==0)sum[i]=sum[i]+x;
            if (i%b==0)sum[i]=sum[i]+y;
        }
        if (get(n)<k){ puts("-1"); continue; }
        int l=0; int r=n;
        while (l<r)
        {
            int mid=(l+r)/2;
            if (get(mid)>=k)r=mid; else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}