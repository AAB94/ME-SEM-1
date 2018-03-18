import random, os

print("**Birthday Simulation**")
trials = 10000

matches = 0
flag = False
random.seed(os.urandom(10))
print("Enter Number of People")
N = int(input())
for z in range(0, trials):
    birthlist = list()
    for i in range(0, N):
        x = random.randint(1, 365)
        birthlist.append(x)
    for j in range(0, len(birthlist)):
        for k in range(j + 1, len(birthlist)):
            if (birthlist[j] == birthlist[k]):
                flag = True
                matches += 1
                break
        if (flag):
            flag = False
            break
res = matches / trials
print("matches -> ", matches)
print(res)
