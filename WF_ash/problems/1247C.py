n,p= map(int,raw_input().split(' '))
l=[]
for i in range(32):
    l.append(2**i + p)
l=l[::-1]
def f(n,i):
    if i == 32:
        if n!=0:
            return -1
    if n==0:
        return 0
    
    ans = -1

    while(1):
        
