-- 상품을 구매한 회원 비율 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131534

# Joined 2021 user ids
with joined_user as (
    SELECT distinct USER_ID from USER_INFO where YEAR(joined) = 2021
)

# Puchased uses
select YEAR(SALES_DATE) as YEAR,
    MONTH(SALES_DATE) AS MONTH,
    COUNT(distinct USER_ID) AS PURCHASED_USERS,
    round(COUNT(distinct USER_ID) / (SELECT count(distinct USER_ID) from joined_user), 1) AS PUCHASED_RATIO
from ONLINE_SALE
where USER_ID in (SELECT USER_ID from joined_user)
group by YEAR, MONTH
order by YEAR, MONTH
