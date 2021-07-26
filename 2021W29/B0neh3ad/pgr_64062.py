'''
    징검다리 건너기
    https://programmers.co.kr/learn/courses/30/lessons/64062
'''
def solution(stones, k):
    sorted_stones = sorted(list(set(stones)))
    min_idx, max_idx = 0, len(sorted_stones)
    mid_idx = 0
    print(sorted_stones)
    while min_idx + 1 < max_idx:
        mid_idx = (min_idx+max_idx) // 2
        key = sorted_stones[mid_idx]
        cnt = 0
        # 건널 수 있는지 확인
        for val in stones:
            if val - (key-1) <= 0:
                cnt += 1
                if cnt == k:
                    cnt = -1
                    break
            else:
                cnt = 0
        if cnt == -1: # 건널 수 없다면
            max_idx = mid_idx
        else: # 건널 수 있다면
            min_idx = mid_idx

    return sorted_stones[min_idx]

print(solution([123,123,321,12,43,23,43,1,5], 1))
'''

시간복잡도를 줄이기 위해...
문제 전체를 단순화하는 방법도 있겠지만
이 문제는 값의 탐색과 확인을 분리해서 생각해야 했다
결국 탐색하는 게 문제였던 거니까,,
탐색과 확인을 동시에 줄이기 위해서 슬라이딩 윈도우로 접근했지만 tc 13에서 계속 막혔다

결론: 문제를 과정별로 쪼개는 방법도 있다!

+parametric search 관련 문제 풀기
s, e = 0, len
while s + 1 < e
return ans[s]
'''