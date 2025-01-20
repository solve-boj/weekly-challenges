-- 조건에 맞는 사원 정보 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284527

select SUM(SCORE) SCORE, g.EMP_NO, EMP_NAME, POSITION, EMAIL
from HR_GRADE g
left join HR_EMPLOYEES e on e.EMP_NO = g.EMP_NO
group by EMP_NO
order by SCORE desc
limit 1
