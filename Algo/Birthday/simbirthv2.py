import random
import os

print("**Birthday Simulation**")
trials = 100000
print("Enter Number of People")
N = int(input())  # Enter Number of People
birth_list = [0]*N
count = 0  # Keeps track if in each Trial atleast 2 share birthday
for i in range(0, trials):
    random.seed(os.urandom(10))
    for j in range(0, N):
        birth_list[j] = random.randint(1, 365)
    for j in birth_list:
        if birth_list.count(j) > 0:
            count += 1
            break
res = count / trials
print(res)
