# Write your MySQL query statement below

Select score, dense_rank() over (order by score desc) AS "rank"
From Scores;
