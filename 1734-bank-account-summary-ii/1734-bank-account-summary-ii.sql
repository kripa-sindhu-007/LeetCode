# Write your MySQL query statement below
SELECT user.name,
       SUM(tran.amount) AS balance
FROM Users user
INNER JOIN Transactions tran ON user.account = tran.account
GROUP BY user.account
HAVING SUM(tran.amount) > 10000;