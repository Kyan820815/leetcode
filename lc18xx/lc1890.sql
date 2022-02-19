-- Q: 1890. The Latest Login in 2020

-- method 1: group by and year function
SELECT  user_id
       ,MAX(time_stamp) AS last_stamp
FROM Logins
WHERE year(time_stamp) = 2020
GROUP BY  user_id