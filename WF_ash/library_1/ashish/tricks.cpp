///outputing something with new line and space 
//here is the reason: " \n" is a char*, " \n"[0] is ' ' and " \n"[1] is '\n'
for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " \n"[j == m];

///use eb instead of pb it is faster than pb(mp())
#define eb emplace_back

///lambda function
[capture list](parameters) -> return value { body }

sort(begin(v), end(v), [] (int a, int b) { return a > b; });

//////Factoradic Number!
Using this you can find k-th lexicographically smallest permutation of size n and vice versa in O(nlogn)

You can apply this cool trick in this Misha and Permutations Summation problem.

