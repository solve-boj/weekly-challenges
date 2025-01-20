-- 주문량이 많은 아이스크림들 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/133027

select FLAVOR
from(
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    from FIRST_HALF f
    group by FLAVOR
    
    union
    
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    from JULY j
    group by FLAVOR
)u
group by FLAVOR
order by SUM(TOTAL_ORDER) desc
limit 3
