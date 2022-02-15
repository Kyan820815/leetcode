-- Q: 1587. Bank Account Summary II

-- method 1: create a table and left join
SELECT  Users.name
       ,tab.balance
FROM
(
	SELECT  account
	       ,SUM(amount) AS balance
	FROM Transactions
	GROUP BY  account
	HAVING SUM(amount) > 10000
) AS tab
LEFT JOIN Users
ON tab.account = Users.account

-- method 2: directly left join
SELECT  Users.name
       ,SUM(Transactions.amount) AS balance
FROM Transactions
LEFT JOIN Users
ON Transactions.account = Users.account
GROUP BY  Transactions.account
HAVING balance > 10000