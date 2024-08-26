# Write your MySQL query statement below
SELECT name, bonus
FROM EMPLOYEE e LEFT JOIN BONUS b 
ON e.empId = b.empid
WHERE bonus < 1000 OR bonus IS NULL