import math

print("Enter Probability")
p = float(input())
print("Enter number of days")
n = int(input())
res = 2*n*math.log(1/(1-p))
res = math.sqrt(res)
print(math.ceil(res))

