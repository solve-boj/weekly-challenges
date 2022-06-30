# 다리를 지나는 트럭
# https://programmers.co.kr/learn/courses/30/lessons/42583

from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0  # 총 시간
    truck_weights = deque(truck_weights)    # 트럭의 무게들
    bridge = deque(0 for _ in range(bridge_length)) # 현재 다리에 있는 트럭의 무게들
    bridge_weight = 0
    
    while bridge:
        tmp = bridge.popleft()
        bridge_weight -= tmp # 현재 다리에 있는 트럭의 무게들의 합
        answer += 1

        if truck_weights:
            if bridge_weight + truck_weights[0] <= weight:
                tmp = truck_weights.popleft()
                bridge.append(tmp)
                bridge_weight += tmp
            else:
                bridge.append(0)
            
    return answer
