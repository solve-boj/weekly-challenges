# 기능개발
# https://programmers.co.kr/learn/courses/30/lessons/42586

import numpy as np

def step(progresses, speeds):
    answer = [] # 최종적으로 return 될 value
    today_done = 0  # 당일 끝낼 work
    for _ in range(100):
        if progresses != None:
            isComplete = []
            progresses = list(np.array(progresses) + np.array(speeds))
            for i in progresses:
                if i >= 100:
                    isComplete.append(True)
                else:
                    isComplete.append(False)
            for j, v in enumerate(isComplete):
                if v == True:
                    today_done+=1
                else: break
            if today_done >= 1:
                answer.append(today_done)
                progresses = progresses[today_done:]
                speeds = speeds[today_done:]
                today_done = 0
    return answer


def solution(progresses, speeds):
    answer = step(progresses, speeds)
    return answer
