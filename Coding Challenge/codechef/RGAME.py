

def f(x,y,i,l,r):
    global a,n
    if i < n:
        return (
            2**(n-i)*(x*y)+f(a[i],l,i+1,a[i],r) +
            f(r,a[i],i+1,l,a[i])
        )
    return x*y

mod = 10**9 + 7
t = int(input().strip())
for _ in range(t):
    n = int(input().strip()) + 1
    a = [int(x) for x in input().strip().split(" ")]
    s = f(a[1],a[0],2,a[1],a[0])
    s = 2*s
    s = s % mod
    print(s)
