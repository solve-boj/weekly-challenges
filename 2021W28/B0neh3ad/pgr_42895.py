'''
    N으로 표현
    https://programmers.co.kr/learn/courses/30/lessons/42895
'''
def solution(N, number):
    # base case
    if number == N:
        return 1
    if number in (N*11, N*2, N*N, 1):
        return 2
    
    # DP array initialization
    nums = []
    for i in range(9):
        nums.append(set())
    if N == 1:
        nums[1] = {1}
        nums[2] = {11, 2}
    else:
        nums[1] = {N}
        nums[2] = {N*11, N*2, N*N, 1}

    # DP
    for i in range(3, 9):
        nums[i].update({int(str(N)*i)})
        for j in range(1, i // 2 + 1):
            nums[i].update({x+y for x in nums[j] for y in nums[i-j]})
            nums[i].update({abs(x-y) for x in nums[j] for y in nums[i-j]})
            nums[i].update({x*y for x in nums[j] for y in nums[i-j]})
            nums[i].update({x // y for x in nums[j] for y in nums[i-j] if y})
            nums[i].update({y // x for x in nums[j] for y in nums[i-j] if x})
        for j in range(1, i):
            nums[i].difference_update(nums[j])
        if number in nums[i]:
            return i
        
    return -1
'''
nums = [set()] * 9로 하니까 shallow copy 되어 버려서 망했었따...
'''