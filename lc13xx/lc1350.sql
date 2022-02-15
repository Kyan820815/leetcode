-- Q: 1350. Students With Invalid Departments

-- method 1: left join
SELECT  Students.id
       ,Students.name
FROM Students
LEFT JOIN Departments
ON Students.department_id = Departments.id
WHERE Departments.id is null


-- method 2: not in
SELECT  id
       ,name
FROM Students
WHERE department_id not IN ( SELECT id FROM Departments)