-- https://www.hackerrank.com/challenges/what-type-of-triangle/problem
SELECT
IF(
    A = B AND B = C, 'Equilateral',
    IF(
        A+B <= C, 'Not A Triangle',
        IF(A = B OR A = C or B = C, 'Isosceles', 'Scalene')
    )
)
FROM TRIANGLES;
