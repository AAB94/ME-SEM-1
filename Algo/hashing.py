import random
import os


def main():
    trials = 1000
    n = 30  # number of bins
    m = 50000 # no of balls
    bin_max = [0]*trials
    random.seed(os.urandom(10))
    for i in range(0,trials):
        arr = [0]*n
        print(i)
        for k in range(0, m):
            r = random.randint(0, n - 1)
            arr[r] += 1
        for j in range(0, n):
            if bin_max[i] < arr[j]:
                bin_max[i] = arr[j]

    sum = 0
    for i in range(0, trials):
        sum += bin_max[i]
    mean = sum / trials

    sum = 0
    for i in range(0,trials):
        sum = sum + ((bin_max[i] - mean)*(bin_max[i] - mean))
    sd = sum / trials
    print("Average of Max numbers hashed to single slot : ", mean)
    print("Standard Deviation : ", sd)

if __name__ == "__main__":
    main()

