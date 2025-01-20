-- 그룹별 조건에 맞는 식당 목록 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131124

select MEMBER_NAME, r.REVIEW_TEXT, DATE_FORMAT(r.REVIEW_DATE, "%Y-%m-%d")
from REST_REVIEW r
join (SELECT MEMBER_ID, COUNT(REVIEW_TEXT) NUM_REVIEW
from REST_REVIEW
group by MEMBER_ID
order by NUM_REVIEW desc
limit 1) m on m.MEMBER_ID = r.MEMBER_ID
join MEMBER_PROFILE p on p.MEMBER_ID = r.MEMBER_ID
order by REVIEW_DATE, REVIEW_TEXT
