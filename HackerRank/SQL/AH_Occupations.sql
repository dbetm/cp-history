-- name (string) Names of people
-- occupation (string){Doctor, Professor, Singer, Actor}

-- https://www.hackerrank.com/challenges/the-pads/problem
SELECT CONCAT(name, "(", LEFT(occupation, 1), ")") FROM OCCUPATIONS ORDER BY name;
SELECT
    CONCAT("There are a total of ", COUNT(occupation), " ", LOWER(occupation), "s.")
FROM OCCUPATIONS GROUP BY occupation ORDER BY COUNT(occupation) ASC, occupation ASC;
