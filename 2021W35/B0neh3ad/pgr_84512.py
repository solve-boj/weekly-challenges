'''
    모음 사전
    https://programmers.co.kr/learn/courses/30/lessons/84512
'''
VOWEL = ["A", "E", "I", "O", "U"]
VOWEL_DICT = {}
val = 1

def make_dict(curr_idx, length, string):
    global val
    if curr_idx == length:
        return
    for i in range(5):
        VOWEL_DICT[string + VOWEL[i]] = val
        val += 1
        make_dict(curr_idx+1, length, string + VOWEL[i])

def solution(word):
    make_dict(0, 5, "")

    return VOWEL_DICT[word]

'''
    조금밖에 없어서 싹 다 구하면 된다
'''