// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 
using namespace std;
const int q = 1e9 + 7;
#define ll long long int
#define int ll
#define d 256 
bool search(string pat, string txt)  
{  
    int M = pat.length();  
    int N = txt.length();  
    int i, j;  
    int p = 0; // hash value for pattern  
    int t = 0; // hash value for txt  
    int h = 1;  
    for (i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
    for (i = 0; i <= N - M; i++)  
    {  
        if ( p == t )  
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j])  
                    break;  
            } 
            if (j == M)  
                return true;  
        }  
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;   
            if (t < 0)  
            t = (t + q);  
        }  
    }
    return false ; 
} 
int32_t main() 
{ 
    string t, s;
    cin >> t;
    cin >> s;
	
	if(search(t, s)) cout << "YES"<<endl;
    else cout << "NO"<< endl; 
	return 0; 
} 
