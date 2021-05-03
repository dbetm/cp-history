-- https://www.hackerrank.com/challenges/revising-the-select-query/problem
SELECT * FROM CITY WHERE POPULATION > 100000 AND COUNTRYCODE = 'USA';

-- https://www.hackerrank.com/challenges/revising-the-select-query-2/problem
SELECT NAME FROM CITY WHERE POPULATION > 120000 AND COUNTRYCODE = 'USA';

-- https://www.hackerrank.com/challenges/select-all-sql/problem
SELECT * FROM CITY;

-- https://www.hackerrank.com/challenges/select-by-id/problem
SELECT * FROM CITY WHERE ID = 1661;

-- https://www.hackerrank.com/challenges/japanese-cities-attributes/problem
SELECT * FROM CITY WHERE COUNTRYCODE = 'JPN';

-- https://www.hackerrank.com/challenges/japanese-cities-name/problem
SELECT NAME FROM CITY WHERE COUNTRYCODE = 'JPN';
