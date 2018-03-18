import random, itertools

n = int(input())
people = [0]*n
for i in range(0,n):
    people[i] = i
x = list(itertools.permutations(people))
trials = 100000
count  = 0
for i in range(0,trials):
    r = random.randint(0,len(x))
    for j in range(0,n):
        if x[r][j] == j:
            count += 1
            break
res = count / trials
print(res)





