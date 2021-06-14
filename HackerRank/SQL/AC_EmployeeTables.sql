-- employee_id is an employee's ID number,
-- name is their name,
-- months is the total number of months they've been working for the company,
-- salary is their monthly salary.

-- https://www.hackerrank.com/challenges/name-of-employees/problem
SELECT name FROM EMPLOYEE ORDER BY name;

-- https://www.hackerrank.com/challenges/salary-of-employees/problem
SELECT name FROM EMPLOYEE WHERE salary > 2000 AND months < 10 ORDER BY employee_id asc;

-- 
