-- https://www.hackerrank.com/challenges/draw-the-triangle-1/problem
-- information_schema_tables is only for running purposes.
SET @cont = 21;
SELECT REPEAT('* ', @cont := @cont - 1) from information_schema.tables;

-- https://www.hackerrank.com/challenges/draw-the-triangle-2/problem
SET @cont = 0;
SELECT REPEAT('* ', @cont := @cont + 1) from information_schema.tables LIMIT 20;
