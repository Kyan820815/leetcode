-- Q: 1777. Product's Price for Each Store

-- method 1: reproduce table with group by
SELECT  product_id
       ,MAX(case WHEN store = 'store1' THEN price else null end) AS store1
       ,MAX(case WHEN store = 'store2' THEN price else null end) AS store2
       ,MAX(case WHEN store = 'store3' THEN price else null end) AS store3
FROM Products
GROUP BY  product_id