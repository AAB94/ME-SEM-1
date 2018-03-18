import random
import math
import os


print("**Enter Number of bins**")
bin_size = int(input())
print("**Enter Number of Trials**")
trials = int(input())   # no of trials
one_bin_empty = [0]*trials
m = 0  # keeps track balls used in 'N' number of Trials
for i in range(0, trials):
    arr = [0]*bin_size
    random.seed(os.urandom(10))
    flag = True
    ball_used = 0  # keeps track of number balls used in each trial
    while True:
        b = random.randint(0, bin_size-1)
        arr[b] += 1
        m += 1
        ball_used += 1
        count = 0   # used to check if all bin have 1 ball
        for j in range(0, bin_size):
            if arr[j] >= 1:
                count += 1
            if count == bin_size - 1 and flag:
                one_bin_empty[i] = ball_used
                flag = False
        if count == bin_size:
            break
res = m / trials
print("Average Balls Needed = ", math.ceil(res), "\n")
for i in range(0, trials):
    print("Trial ", i, " No of Balls used when Exactly one bin empty ", one_bin_empty[i])

