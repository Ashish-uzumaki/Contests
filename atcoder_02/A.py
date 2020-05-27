n, a, b, c, d = map(int, raw_input().split()) 
cost = 2**100
for i in range(0, 63):
    for j in range(0, 50):
        for k in range(0, 38):
            ans = pow(2, i)*pow(3, j)*pow(5, k)
            temp = (i * a) + (j * b) + (k * c)
            cost = min(cost, temp + (abs(n - ans) * d) + d)
print(cost)