-- Q: 0175. Combine Two Tables

-- method 1: left join
SELECT  Person.firstName AS firstName
       ,Person.lastName  AS lastName
       ,Address.city     AS city
       ,Address.state    AS state
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId