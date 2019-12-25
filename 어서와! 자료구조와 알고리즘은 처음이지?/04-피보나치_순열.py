# 인자로 0 또는 양의 정수인 x 가 주어질 때, Fibonacci 순열의 해당 값을 구하여 반환하는 함수 solution() 을 완성하세요.
from functools import lru_cache
# LRU cache = Least Recently Used cache


@lru_cache(maxsize=1000)
def solution(x):
    # Check that the input is a positive integer
    if type(x) != int:
        raise TypeError("n must be a positive int")
    if x < 0:
        raise ValueError("n must be a positive int")

    if x < 2:
        return x
    else:
        return solution(x - 2) + solution(x - 1)
    return x


for n in range(1, 1001):
    print(n, ":", solution(n))