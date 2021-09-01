-- N (integer) value of a node in Binary Tree.
-- P (integer) parent of N.

-- WRONG
SELECT N,
IF(
    P = NULL, 'Root',
    IF(COUNT(P) > 1, 'Inner', 'Leaf')
)
FROM BST GROUP BY P ORDER BY N;
