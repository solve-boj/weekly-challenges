# 가사 검색
# https://programmers.co.kr/learn/courses/30/lessons/60060

# *효율성 테스트 탈락*

def solution(words, queries):
    answer = []

    for v in queries:
        answer.append(SearchWords(words, v))
    
    return answer

def SearchWords(words, query):
    target_result = []
    for v in words:
        if len(v) == len(query):
            detect_question = DetectQuestions(query)
            for loc, k in enumerate(detect_question):
                if loc == 0:
                    tmp = list(v)
                if k == 1:
                    tmp[loc] = "?"

            for where, j in enumerate(DetectQuestions(tmp)):
                if j == 1:
                    list(tmp)[where] = '?'

            if "".join(tmp) == query:
                target_result.append(v)

    return len(target_result)

def DetectQuestions(string):
    star_locate = []
    for v in string:
        if v == '?':
            star_locate.append(1)
        else:
            star_locate.append(0)
    return star_locate

# 기댓값 [3, 2, 4, 1, 0]
# solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"])
