-- Q: 1873. Calculate Special Bonus

-- method 1: not like, if
SELECT  employee_id
       ,(case WHEN employee_id % 2 = 1 AND name not like 'M%' THEN salary else 0 end) AS bonus
FROM Employees
ORDER BY employee_id