
class node():
    def __init__(self,l,r):
        self.l = l
        self.r = r
        self.val = 0
        self.left = None
        self.right = None
        self.to_update = False


def build(cur,l,r):
    if l == r:
        return None
    else:
        mid = (l+r)//2
        cur.left = node(l,mid)
        cur.right = node(mid+1,r)
        leftnode = cur.left
        rightnode = cur.right
        build(leftnode,l,mid)
        build(rightnode,mid+1,r)
        
def update(cur,l,r,val,parent=None):
    m = (cur.l+cur.r)//2
    if cur.l == l and cur.r == r:
        cur.val += val
    elif l <= m and r <= m:
        update(cur.left,l,r,val,cur)
    elif l > m and r <=cur.r:
        update(cur.right,l,r,val,cur)
    elif l <= m and r > m:
        update(cur.left,l,m,val,cur)
        update(cur.right,m+1,r,val,cur)
        
ans = 0   
def max_val(cur):
    if cur != None:
        global ans
        if cur.val > ans:
            ans = cur.val
        max_val(cur.left)
        max_val(cur.right)
	 

def main():
    n,m = input().strip().split()
    n,m = int(n),int(m)
    root = node(1,n)
    build(root,1,n)
    for i in range(0,m):
        a,b,k = input().strip().split()
        a,b,k = int(a),int(b),int(k)
        update(root,a,b,k)
    max_val(root)
    global ans
    print(ans)
if __name__ == "__main__":
    main()
