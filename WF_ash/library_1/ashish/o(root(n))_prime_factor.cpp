    ////////order(root(n)) prime factorization///////////
    vector<int> primes;
    int lol = x;
    for (int i = 2; i * i <= x; i++) {
        if (lol % i == 0) {
            primes.push_back(i);
            while (lol % i == 0) {
                lol /= i;
            }
        }
    }
    if (lol > 1) {
        primes.push_back(lol);
    }
    // \\binary Search on answer 
    int binsearch(int start, int lo, int hi, int shouldbe){
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(query(start, mid)==shouldbe)
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}
