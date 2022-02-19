-- Q: 1821. Find Customers WITH Positive Revenue this Year

-- method 1: group by with having
SELECT  customer_id
FROM Customers
WHERE year = 2021
GROUP BY  customer_id
HAVING SUM(revenue) > 0