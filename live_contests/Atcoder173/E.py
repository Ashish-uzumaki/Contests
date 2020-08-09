def maxProductSubarrayOfSizeK(A, n, k): 
    A.sort() 
    product = 1
    if (A[n - 1] == 0 and (k & 1)): 
        return 0
    if (A[n - 1] <= 0 and (k & 1)) : 
        for i in range(n - 1, n - k + 1, -1): 
            product *= A[i] 
        return product 
    i = 0
    j = n - 1
    if (k & 1): 
        product *= A[j] 
        j = j - 1
        k = k - 1 
    k = k >> 1 
    for itr in range( k) : 
        left_product = A[i] * A[i + 1] 
        right_product = A[j] * A[j - 1] 
 
        if (left_product > right_product) : 
            product = product * left_product 
            i = i +  2
          
        else : 
            product = product * right_product 
            j = j - 2 
    return product
x, y = map(int, input().split())
l = list(map(int, input().split()))
MOD = 1000000007
ans = maxProductSubarrayOfSizeK(l, x, y)
print(ans)
ans = ((ans % MOD) + MOD) % MOD
# ans = ans % (1000000007)
print(ans)
