-- https://www.hackerrank.com/challenges/the-blunder/problem
SELECT CEIL(
    AVG(Salary) -
    AVG(CAST(REPLACE(CAST(Salary AS CHAR), '0', '') AS SIGNED))
) FROM EMPLOYEES;
