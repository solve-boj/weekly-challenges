-- 5월 식품들의 총매출 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131117

SELECT o.PRODUCT_ID, p.PRODUCT_NAME, SUM(p.PRICE * o.AMOUNT) AS TOTAL_SALES
from FOOD_ORDER o
right join FOOD_PRODUCT p on p.PRODUCT_ID = o.PRODUCT_ID
where PRODUCE_DATE between '2022-05-01' and '2022-05-31'
group by PRODUCT_ID
ORDER BY TOTAL_SALES DESC, p.PRODUCT_ID ASC
