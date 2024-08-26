SELECT contest_id, ROUND(COUNT(DISTINCT Register.user_id)/COUNT(DISTINCT Users.user_id)*100,2) AS percentage 
FROM Users, Register 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC