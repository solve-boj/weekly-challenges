# 소수 만들기
# https://programmers.co.kr/learn/courses/30/lessons/12977

def is_prime(num):
    for i in range(2, num):
        if num % i == 0 and num != i:
            return False
    return True

def get_prim_num(nums):
    prim_list = []
    num_len = len(nums)
    
    for i in range(num_len):
        for j in range(i+1, num_len):
            for k in range(j+1, num_len):
                sum_num = nums[i] + nums[j] + nums[k]
                if is_prime(sum_num): 
                    prim_list.append(sum_num)
    return prim_list

def solution(nums):
    return len(get_prim_num(nums))
