-- Q: 1795. Rearrange Products Table

-- method 1: union
SELECT  product_id
       ,'store1' AS store
       ,store1   AS price
FROM Products
WHERE store1 is not null union
SELECT  product_id
       ,'store2' AS store
       ,store2   AS price
FROM Products
WHERE store2 is not null union
SELECT  product_id
       ,'store3' AS store
       ,store3   AS price
FROM Products
WHERE store3 is not null

-- method 2: unpivot, not supported by sql
SELECT  product_id
       ,store
       ,price
FROM Products UNPIVOT
( price FOR store IN (store1, store2, store3)
) AS T