-- Q: 1581. Customer Who Visited but Did Not Make Any Transactions

-- method 1: exclusive left join 
SELECT  Visits.customer_id
       ,COUNT(*) AS count_no_trans
FROM Visits
LEFT JOIN Transactions
ON Visits.visit_id = Transactions.visit_id
WHERE Transactions.visit_id is null
GROUP BY  Visits.customer_id