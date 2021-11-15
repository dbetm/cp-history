-- https://www.hackerrank.com/challenges/weather-observation-station-1/problem
SELECT CITY, STATE FROM STATION;

-- https://www.hackerrank.com/challenges/weather-observation-station-2/problem
SELECT ROUND(SUM(LAT_N), 2) AS lat, ROUND(SUM(LONG_W), 2) AS lon FROM STATION;

-- https://www.hackerrank.com/challenges/weather-observation-station-3/problem
SELECT DISTINCT CITY FROM STATION WHERE ID % 2 = 0;

-- https://www.hackerrank.com/challenges/weather-observation-station-4/problem
SELECT COUNT(*) - COUNT(DISTINCT CITY) FROM STATION;

-- https://www.hackerrank.com/challenges/weather-observation-station-5/problem
SELECT CITY, LENGTH(CITY) shortest FROM STATION ORDER BY shortest ASC, CITY ASC LIMIT 1;
SELECT CITY, LENGTH(CITY) longest FROM STATION ORDER BY longest DESC, CITY DESC LIMIT 1;

-- https://www.hackerrank.com/challenges/weather-observation-station-6/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY LIKE 'a%' OR CITY LIKE 'e%' OR CITY LIKE 'i%' OR CITY LIKE 'o%' OR CITY LIKE 'u%';
-- Another solution
-- select distinct CITY from STATION where CITY RLIKE '^[AEIOU]';

-- https://www.hackerrank.com/challenges/weather-observation-station-7/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY RLIKE '[AEIOU]$';

-- https://www.hackerrank.com/challenges/weather-observation-station-8/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY RLIKE '[AEIOU]$' AND CITY RLIKE '^[AEIOU]';

-- https://www.hackerrank.com/challenges/weather-observation-station-9/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY NOT RLIKE '^[AEIOU]';

-- https://www.hackerrank.com/challenges/weather-observation-station-10/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY NOT RLIKE '[AEIOU]$';

-- https://www.hackerrank.com/challenges/weather-observation-station-11/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY NOT RLIKE '^[AEIOU]' OR CITY NOT RLIKE '[AEIOU]$';

-- https://www.hackerrank.com/challenges/weather-observation-station-12/problem
SELECT DISTINCT CITY FROM STATION WHERE CITY NOT RLIKE '^[AEIOU]' AND CITY NOT RLIKE '[AEIOU]$';

-- https://www.hackerrank.com/challenges/weather-observation-station-13/problem
SELECT ROUND(SUM(LAT_N), 4) FROM STATION WHERE LAT_N > 38.7880 AND LAT_N < 137.2345;

-- https://www.hackerrank.com/challenges/weather-observation-station-14/problem
SELECT TRUNCATE(MAX(LAT_N), 4) FROM STATION WHERE LAT_N < 137.2345;

-- https://www.hackerrank.com/challenges/weather-observation-station-15/problem
SELECT ROUND(LONG_W, 4) FROM STATION WHERE LAT_N < 137.2345 ORDER BY LAT_N DESC LIMIT 1;

-- https://www.hackerrank.com/challenges/weather-observation-station-16/problem
SELECT ROUND(MIN(LAT_N), 4) FROM STATION WHERE LAT_N > 38.7780;

-- https://www.hackerrank.com/challenges/weather-observation-station-17/problem
SELECT ROUND(LONG_W, 4) FROM STATION WHERE LAT_N > 38.7780 ORDER BY LAT_N ASC LIMIT 1;

-- https://www.hackerrank.com/challenges/weather-observation-station-18/problem
SELECT ROUND(ABS(MIN(LAT_N)-MAX(LAT_N)) + ABS(MIN(LONG_W)-MAX(LONG_W)), 4) FROM STATION;

-- https://www.hackerrank.com/challenges/weather-observation-station-19
SELECT
ROUND(SQRT(POWER(MIN(LAT_N)-MAX(LAT_N), 2) + POWER(MIN(LONG_W)-MAX(LONG_W), 2)), 4)
FROM STATION;

-- https://www.hackerrank.com/challenges/weather-observation-station-20/problem
-- compute median
SELECT ROUND(AVG(dd.LAT_N), 4)
FROM (
SELECT S.LAT_N, @rownum:=@rownum+1 as `row_number`, @total_rows:=@rownum
  FROM STATION S, (SELECT @rownum:=0) r
  ORDER BY S.LAT_N
) as dd
WHERE dd.row_number IN (FLOOR((@total_rows+1) / 2), FLOOR((@total_rows+2) / 2));
