# 리스트 L 과 정수 x 가 인자로 주어질 때, 리스트 내의 올바른 위치에 x 를 삽입하여 그 결과 리스트를 반환하는 함수 solution 을 완성하세요.

L = [20, 37, 58, 72, 91]
x = 65

def solution(L,x):
    for k in L:
        if x < k:
            spot = L.index(k)
            break
        else:
            spot = len(L)
    answer = L
    answer.insert(spot, x)
    return answer

print(solution(L,x))