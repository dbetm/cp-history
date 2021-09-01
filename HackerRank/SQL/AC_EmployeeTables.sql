-- employee_id is an employee's ID number,
-- name is their name,
-- months is the total number of months they've been working for the company,
-- salary is their monthly salary.

-- https://www.hackerrank.com/challenges/name-of-employees/problem
SELECT name FROM EMPLOYEE ORDER BY name;

-- https://www.hackerrank.com/challenges/salary-of-employees/problem
SELECT name FROM EMPLOYEE WHERE salary > 2000 AND months < 10 ORDER BY employee_id asc;

--https://www.hackerrank.com/challenges/earnings-of-employees/problem
SELECT MAX(salary * months), COUNT(*)
FROM EMPLOYEE
WHERE (salary * months) = (SELECT MAX(salary * months) FROM EMPLOYEE);
-- alternative
-- select months*salary, count(*) from Employee group by 1 order by 1 desc limit 1;
