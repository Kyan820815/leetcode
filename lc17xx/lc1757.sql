-- Q: 1757. Recyclable AND Low Fat Products

-- method 1: simple
SELECT  product_id
FROM Products
WHERE low_fats = 'Y'
AND recyclable = 'Y'