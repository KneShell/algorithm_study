# 문제 설명 
# 입력으로 주어지는 리스트 x 의 첫 원소와 마지막 원소의 합을 리턴하는 함수 solution() 을 완성하세요.

some_list = [5, 3, 8, 2]

def solution(x):
    answer = x[0] + x[-1]
    return answer

print("주어진 리스트의 첫 원소와 마지막 원소의 합 : {i}".format(i = solution(some_list)))