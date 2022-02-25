-- 입양 시각 구하기(1)
-- https://programmers.co.kr/learn/courses/30/lessons/59412

SELECT HOUR(DATETIME) AS hour,
COUNT (DATETIME) AS COUNT
FROM ANIMAL_OUTS
GROUP BY hour
HAVING hour > 8 AND hour < 20
ORDER BY hour ASC
