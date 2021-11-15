-- https://www.hackerrank.com/challenges/contest-leaderboard/problem
SELECT h.hacker_id, h.name, SUM(max_score.score) as total_score
FROM Hackers as h
INNER JOIN (
    SELECT hacker_id, MAX(score) AS score FROM Submissions
    GROUP BY challenge_id, hacker_id
) max_score ON h.hacker_id = max_score.hacker_id
GROUP BY h.hacker_id, h.name
HAVING total_score > 0
ORDER BY total_score DESC, h.hacker_id ASC;
