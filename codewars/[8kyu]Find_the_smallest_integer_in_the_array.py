# Given an array of integers your solution should find the smallest integer.

test_list = [34, 15, 88, 2]

def find_smallest_int(arr):
    arr.sort()
    return arr[0]

# Comment: You shouldn't do that for two reasons: 
# a) you are changing the input value, which is error-prone and 
# b) sorting a sequence has a complexity of round about O(n * log(n)), 
# while finding the minimum of a sequence can very easily be done in O(n).

def findSmallestInt2(arr):
    return min(arr)

def findSmallestInt3(arr):
    a=arr[0]
    for i in range(1,len(arr)):
        if arr[i]<a:
            a=arr[i]
    return a