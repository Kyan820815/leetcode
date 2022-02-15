-- Q: 1378. Replace Employee ID With The Unique Identifier

-- method 1: left join
SELECT  EmployeeUNI.unique_id
       ,Employees.name
FROM Employees
LEFT JOIN EmployeeUNI
ON EmployeeUNI.id = Employees.id