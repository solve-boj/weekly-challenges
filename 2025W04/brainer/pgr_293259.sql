-- 잡은 물고기의 평균 길이 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/293259

select round(AVG(IFNULL(LENGTH, 10)), 2) as AVERAGE_LENGTH
from FISH_INFO
