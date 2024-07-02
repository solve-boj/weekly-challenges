-- https://school.programmers.co.kr/learn/courses/30/lessons/131530

SELECT CONCAT(SUBSTRING_INDEX(price / 10000, ".", 1), "0000") AS PRICE_GROUP, COUNT(product_code)
FROM PRODUCT
GROUP BY PRICE_GROUP
ORDER BY PRICE_GROUP ASC
