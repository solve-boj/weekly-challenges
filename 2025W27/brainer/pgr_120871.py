def find_three_time(n = 1000):
    return [x for x in range(1, n + 1) if x % 3 == 0]
           
def find_using_three():
    num_list = [i for i in range(1, 1000)]
    new_list = []
    for i in num_list:
        if '3' in list(set(str(i))):
            new_list.append(int(i))
    return new_list
            
def solution(n):
    answer = 0
    num_list = [i for i in range(1, 1000)]
    
    return list(set(num_list) - set(find_three_time()) - set(find_using_three()))[n-1]

