-- Q: 1741. Find Total Time Spent by Each Employee

-- method 1: sum and group by
SELECT  event_day             AS day
       ,emp_id
       ,SUM(out_time-in_time) AS total_time
FROM Employees
GROUP BY  day
         ,emp_id