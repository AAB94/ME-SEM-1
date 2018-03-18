mod = 10**9 + 7
t = int(input().strip())
for _ in range(t):
    n = int(input().strip()) + 1
    a = [int(x) for x in input().strip().split(" ")]
    s = 0
    for i in range(n):
        if i == 0:
            m = 2
        else:
            m = 2**i
        temp = 0
        for j in range(i+1,n):
            temp = temp + 2**(n-(j+1))*(a[i]*a[j])
        temp = m*temp
        s = s + temp
    s = s % mod
    print(s)
