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

	int query(int lef, int rig , int k, int& sum )
	{
		if(sum >= k + lef - 1 || sum > rig)
		{
			return 1 ;   
		}
		else
		{
			sum = sum + tr[1].sum ;
			// cout<< tr[1].sum << endl;
			return 0 ;  
		}
	}

};

void read()
{
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i] ;
	}
    // for(int i = 0; i <n; i++){cout << arr[i]<<" ";}
}

segment_tree t[26];

void convert(int j)
{
	for(int i=0 ; i<n ; i++)
	{
		char c = 'a' + j;
		if(arr[i] == c)
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
	for(int i = 0 ; i < 26 ; i++)
	{
		convert(i) ; 
		t[i].init(0, n - 1, 0);
		for(int j = 0; j< 20; j++){
			cout<< t[i].tr[j].sum<<" ";
		}
		cout << endl;
	}
	

	for(int j = 0; j < m; j++)
	{
		int query ; 
		cin >> query ; 
		if(query == 0)
		{
			int index ; 
			char input ; 
			cin >> index >> input ; 
			int a = (int)(input) - 97 ; 
			t[a].update(index - 1 , 1 , 0 , n-1 , 0) ;
			t[index].update(index - 1 , 0 , 0 , n-1 , 0) ;
		}

		else
		{
			int l , r, k ;
			cin >> l >> r >> k ;
			int sum = 0; 
			int i = 0; 
			l--,r--;
			for(int i = 0 ; i < 26 ; i++)
			{
				// cout<<t[i].query(l , r, k , sum )<<" " sum << endl;
				if(t[i].query(l , r, k , sum ))
				{
					i-- ; 
					cout << (char)(97 + i)  << endl ; 
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

	read() ;
	solve() ;

}