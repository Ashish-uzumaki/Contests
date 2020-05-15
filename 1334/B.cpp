#include <bits/stdc++.h> 
using namespace std ; 


int most_frequency(unordered_map<int, int> hash_table) 
{    
    int max_count = 0, res = -1; 
    for (auto i : hash_table) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
} 


unordered_map<int ,int> create_hash_table(int arr[] , int n )
{
	unordered_map<int , int > hash_table ; 

	for(int i=0 ; i< n  ;i++)
	{
		hash_table[arr[i]] += 1 ; 
	}

	return hash_table ;
}


int add(int x ,  unordered_map<int ,int>& hash_table )
{
	int count = hash_table[x] ; 
	hash_table.insert({x , count++}) ;
	return 0; 
}


int delete_max_freq( unordered_map<int ,int>& hash_table , int n , int arr[])
{
	int most_frequent = most_frequency(hash_table) ; 
	
	hash_table.erase(most_frequent) ;

	while(most_frequent == most_frequency(hash_table))
	{
		hash_table.erase(most_frequent) ; 
	}
	return 0; 
}

int print(unordered_map<int ,int> hash_table )
{
	for (auto x : hash_table) 
    {
    	cout << x.first << " ==>> " << x.second << endl; 
	}
	return 0; 
}


int main()
{
	int n ; 
	cin >> n ; 
	int arr[n] ; 

	for(int i=0 ; i<n ; i++)
	{
		cin >> arr[i]  ; 
	}

	unordered_map <int ,int> hash_table = create_hash_table(arr , n);

	char query ;

	cin >> query ; 

	if(query == 'a')
	{
		int input ;
		cin >> input ; 
		add(input , hash_table) ;
		print(hash_table) ; 

	} 

	if(query == 'd')
	{
		delete_max_freq(hash_table , n , arr ) ;
		print(hash_table) ;
	}
	return 0; 
}
