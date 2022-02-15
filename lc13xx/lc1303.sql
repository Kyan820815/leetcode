-- Q: 1303. Find the Team Size

-- method 1: partition
SELECT  employee_id
       ,COUNT(*) over (partition by team_id) AS team_size
FROM Employee