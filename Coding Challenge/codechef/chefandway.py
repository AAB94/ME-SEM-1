def min_cost(src, dest, table, dest_cost):
    if src == dest:
        res = dest
    elif src in dest_cost:
        res = dest_cost[src]
    else:
        min_val = None
        for key in table[src]:
            temp = src * min_cost(key, dest, table, dest_cost)
            if min_val is None:
                min_val = temp
            elif min_val > temp:
                min_val = temp
        dest_cost[src] = min_val
        res = dest_cost[src]
    return res

def main():
    n,k  = input().strip().split(" ")
    n,k = int(n),int(k)
    arr = [int(x) for x in input().strip().split(" ")]
    mod = 1000000007
    table = {}
    dest_cost = {}
    for i in range(0, n-1):
        table[arr[i]] = {}
        for j in range(i+1, n):
            if arr[j] - arr[i] <= k:
                table[arr[i]][arr[j]] = arr[j] - arr[i]
    ans = min_cost(arr[0], arr[n-1], table, dest_cost)
    ans = ans % mod
    print(ans)

if __name__ == "__main__":
    main()
