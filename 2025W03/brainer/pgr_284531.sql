-- 노선별 평균 역 사이 거리 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284531

select 
    ROUTE,
    CONCAT(round(sum(D_BETWEEN_DIST), 1), 'km') AS TOTAL_DISTANCE,
    CONCAT(round(AVG(D_BETWEEN_DIST), 2), "km") AS AVERAGE_DISTANCE
from SUBWAY_DISTANCE
group by route
order by sum(D_BETWEEN_DIST) desc