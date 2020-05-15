#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 18);

int n, m;
char arr[MAXN];
int a[MAXN] ;

struct node
{
	int sum;

	node() {sum = 0;}
	node(int val)
	{
		sum = val;
	}
};

node temp, broken;

node merge(node l, node r)
{
	temp.sum = l.sum + r.sum;
	return temp;
}

struct segment_tree
{
	node tr[4 * MAXN];

	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx] = node(a[l]);
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	void update(int pos, int val, int l, int r, int idx)
	{
		if(l > pos || r < pos)
			return;

		if(l == r && l == pos)
		{
			tr[idx].sum += val;
			return;
		}

		int mid = (l + r) >> 1;
		update(pos, val, l, mid, 2 * idx + 1);
		update(pos, val, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	char query(int lef, int rig , int k, int* sum )
	{
		if(*sum >= k + lef - 1 || *sum > rig)
		{
			return 1 ;   
		}
		else
		{
			*sum = *sum + tr[0].sum ;
			return 0 ;  
		}
	}

};

void read()
{
	cin >> n >> m;
	cout << "y" ; 
	for(int i=0 ; i<n ; i++)
	{
		cin >> arr[i] ; 
	}
	cout << "y" ; 
}

segment_tree t[26];

void convert(int j)
{
	for(int i=0 ; i<n ; i++)
	{
		if(arr[i] == 97 + j + '0')
		{
			a[i] = 1 ; 
		}
		else
		{
			a[i] = 0 ; 
		}
	}
}

void solve()
{
	for(int i=0 ; i<26 ; i++)
	{
		convert(i) ; 
		t[i].init(0, n - 1, 0);
	}
	

	for(int i = 0; i < m; i++)
	{
		int query ; 
		cin >> query ; 
		cout <<"y" ; 
		if(query == 0)
		{
			int index ; 
			char input ; 
			cin >> index >> input ; 
			for(int i=0 ; i<26 ; i++)
			{
				t[i].update(index -1, input , 0 , n-1 , 0) ; 
			}
		}

		else
		{
			int l , r, k ;
			cin >> l >> r >> k ;
			int sum = 0 ; 
			int i =0 ; 
			for(int i=0 ; i<26 ; i++)
			{
				if(t[i].query(l , r, k , &sum ))
				{
					i-- ; 
					cout << 97 + i +'0' << endl ; 
					break ; 
				}
				else
				{
					continue ; 
				}
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	read() ;
	solve() ;

}