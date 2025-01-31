-- 경기도에 위치한 식품창고 목록 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131114

SELECT WAREHOUSE_ID,
    WAREHOUSE_NAME,
    ADDRESS,
    ifnull(FREEZER_YN, "N") AS FREEZER_YN
from FOOD_WAREHOUSE
where address like ("경기도%")
order by WAREHOUSE_ID
