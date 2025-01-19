-- ROOT 아이템 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/273710#

select ITEM_ID, ITEM_NAME
from ITEM_INFO
where ITEM_ID in (select ITEM_ID from ITEM_TREE where PARENT_ITEM_ID is null)
order by ITEM_ID
