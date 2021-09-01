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

-- https://www.hackerrank.com/challenges/revising-aggregations-the-count-function/problem
SELECT COUNT(*) FROM CITY WHERE POPULATION > 100000;

-- https://www.hackerrank.com/challenges/revising-aggregations-sum/problem
SELECT SUM(POPULATION) FROM CITY WHERE DISTRICT = 'California';

-- https://www.hackerrank.com/challenges/revising-aggregations-the-average-function/problem
SELECT AVG(POPULATION) FROM CITY WHERE DISTRICT = 'California';

-- https://www.hackerrank.com/challenges/average-population/problem
SELECT CAST(AVG(POPULATION) AS SIGNED) FROM CITY;

-- https://www.hackerrank.com/challenges/japan-population/problem
SELECT SUM(POPULATION) FROM CITY WHERE COUNTRYCODE = 'JPN';

-- https://www.hackerrank.com/challenges/population-density-difference/problem
SELECT MAX(POPULATION) - MIN(POPULATION) FROM CITY;

-- https://www.hackerrank.com/challenges/average-population-of-each-continent/problem
SELECT COUNTRY.CONTINENT, FLOOR(AVG(CITY.POPULATION)) AS AVERAGE_POPULATION
FROM COUNTRY
INNER JOIN CITY
ON COUNTRY.CODE = CITY.COUNTRYCODE
GROUP BY COUNTRY.CONTINENT
ORDER BY AVERAGE_POPULATION;

-- https://www.hackerrank.com/challenges/african-cities/problem
SELECT CITY.NAME
FROM COUNTRY
INNER JOIN CITY
ON COUNTRY.CODE = CITY.COUNTRYCODE
WHERE COUNTRY.CONTINENT = 'Africa';

-- https://www.hackerrank.com/challenges/asian-population/problem
SELECT SUM(CITY.POPULATION)
FROM COUNTRY
INNER JOIN CITY
ON COUNTRY.CODE = CITY.COUNTRYCODE
WHERE COUNTRY.CONTINENT = 'Asia';
