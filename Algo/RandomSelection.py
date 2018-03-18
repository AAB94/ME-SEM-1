import random
import os
import math


def main():
    size = 10000
    arr = [0] * size
    set_array(arr, size)
    check_ans(arr, size)
    median = get_median(arr)
    ans = random_selection(arr, median)
    print(" The Median is ", ans)


def random_selection(arr, median, step=0):
    l = 0
    r = len(arr) - 1
    flag = False
    step += 1  # Keeps track of number of times random_selection method is called
    phase = 0  # how many times the pivot chosen to ensure it lies close to the median
    print()
    print(" Step : ", step, " Size of Array : ", len(arr), end="")

    if len(arr) == 1:
        return arr[0]
    else:
        while not flag:
            phase += 1
            index = random.randint(l, r)
            flag = check(arr, index)
        print(" Phases : ", phase)
        arr[l], arr[index] = arr[index], arr[l]  # swapping chose pivot element with 0 index for partition process
        res = partition(arr)
        if median == res:
            return arr[median]
        elif res < median:
            l = res + 1
            return random_selection(arr[l:], median - res - 1, step)
            # since array begin from 0 eg res = 2 means 3 elements removing 1 more

        elif res > median:
            r = res - 1
            return random_selection(arr[:r+1], median, step)


def partition(arr, p=0):
    l = 0
    r = len(arr) - 1
    x = arr[p]
    while l < r:
        while l < len(arr) and arr[l] <= x:
            l += 1
        while r > -1 and arr[r] > x:
            r -= 1
        if l < r:
            arr[l], arr[r] = arr[r], arr[l]  # swap values
    arr[p], arr[r] = arr[r], arr[p]
    return r  # return chosen random pivot element final position


'''
Check if chosen element near median
'''
def check(arr, p):
    count = 0
    size = len(arr)
    for i in range(0, size):
        if arr[i] < arr[p]:
            count += 1
    if count <= math.floor( 0.75*size ) and count >= math.floor( 0.25*size ):
        return True
    return False


'''
Returns the Position of Median in a Sorted Array
'''
def get_median(arr):
    ans = len(arr)//2
    if len(arr) % 2 == 0:
        ans = ans - 1
    return ans


'''
Fills the array with random values for a given size
'''
def set_array(arr, size):
    random.seed(os.urandom(10))
    for i in range(0, size):
        arr[i] = random.randint(0, 50000)


def check_ans(arr, size):
    narr = [0]*size
    for i in range(0, size):
        narr[i] = arr[i]
    narr.sort()
    ans = len(arr)//2
    if len(arr) % 2 == 0:
        ans = ans - 1
    print("Sorted Array ", narr)
    print(" The Answer should match with this -> ", narr[ans])


if __name__ == "__main__":
    main()
