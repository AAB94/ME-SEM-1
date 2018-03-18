import random
import os

'''
Give back Hats to people
'''


def hat(arr, n):
    random.seed(os.urandom(10))
    for i in range(0, n):
        r = random.randint(0, n - 1)
        while r in arr:
            r = random.randint(0, n - 1)
        arr.append(r)


print("**Hat Checker**")
print("Enter Number of People")
n = int(input())
trials = 100000
count = 0
for i in range(0, trials):
    arr = list()  # represents people with hats
    hat(arr, n)
    for j in range(0, n):
        if arr[j] == j:
            count += 1
res = count / trials
print(res)
