"""
전화번호 목록
https://programmers.co.kr/learn/courses/30/lessons/42577
"""

"""
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false
"""

def solution(phone_book):
    answer = True
    phone_book = sorted(phone_book)
    for i, phone in enumerate(phone_book):
        if i == len(phone_book) - 1:
            break
        if phone_book[i+1].startswith(phone):
            answer = False
            break
    return answer

if __name__ == '__main__':
    print(solution(["119", "97674223", "1195524421"]))
    print(solution(["123","456","789"]))
    print(solution(["12","123","1235","567","88"]))
    
    