-- 대여 횟수가 많은 자동차들의 월별 대여 횟수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/151139

WITH FREQUENT_CARS AS (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
    group by CAR_ID
    HAVING COUNT(*) >= 5
)

select MONTH(start_date) AS MONTH, CAR_ID, COUNT(*) AS RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where 1=1
AND CAR_ID IN (SELECt CAR_ID FROM FREQUENT_CARS)
AND START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
group by MONTH, CAR_ID
order by MONTH, CAR_ID DESC
