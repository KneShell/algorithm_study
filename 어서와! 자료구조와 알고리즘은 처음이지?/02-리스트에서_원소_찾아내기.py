# 인자로 주어지는 리스트 L 내에서, 또한 인자로 주어지는 원소 x 가 발견되는 모든 인덱스를 구하여 이 인덱스들로 이루어진 리스트를 반환하는 함수 solution 을 완성하세요.
L = [64, 72, 83, 72, 54]
x = 49


def solution(L, x):
    answer = []
    for index, value in enumerate(L):
        if x == value:
            answer.append(index)
    if not answer:
        answer = [-1]
    return answer


print(solution(L, x))
