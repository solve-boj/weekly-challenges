-- 자동차 대여 기록에서 대여중 / 대여 가능 여부 구분하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/157340

with AVAILABLE_CARS AS (
    SELECT CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where '2022-10-16' BETWEEN START_DATE AND END_DATE OR END_DATE = '2022-10-16'
)

select DISTINCT CAR_ID, 
    case when CAR_ID IN (SELECT CAR_ID FROM AVAILABLE_CARS) THEN "대여중"
        ELSE "대여 가능"
    END AS AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
order by CAR_ID DESC
