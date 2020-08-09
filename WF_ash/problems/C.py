def binaryToDecimal(n): 
    return int(n,2)
for _ in range(input()):
    a=raw_input()
    b=raw_input()
    a=binaryToDecimal(a)
    b=binaryToDecimal(b)
    cnt=0
    while b>0:
        x=a^b
        y=a&b
        a=x
        b=2*y
        cnt+=1
    print cnt
