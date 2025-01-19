-- 조건에 맞는 도서와 저자 리스트 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/144854

select b.BOOK_ID, a.AUTHOR_NAME, DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d') AS PUBLISHED_DATE
from BOOK b
inner join AUTHOR a on a.author_id = b.author_id
where b.CATEGORY = '경제'
order by PUBLISHED_DATE
