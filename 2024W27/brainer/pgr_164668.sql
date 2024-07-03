SELECT *
FROM (
SELECT USER_ID, NICKNAME, SUM(PRICE) AS TOTAL_SALES
FROM USED_GOODS_BOARD ub
LEFT JOIN USED_GOODS_USER uu
ON ub.WRITER_ID = uu.USER_ID
WHERE STATUS = 'DONE'
GROUP BY USER_ID
) total
WHERE TOTAL_SALES >= 700000
ORDER BY TOTAL_SALES ASC