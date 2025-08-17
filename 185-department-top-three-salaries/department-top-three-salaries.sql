# Write your MySQL query statement below
WITH salary_analysis AS (
  SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary,
    DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) AS salary_rank
  FROM Department d
  JOIN Employee e
    ON d.id = e.departmentId
)
SELECT Department, Employee, Salary
FROM salary_analysis
WHERE salary_rank <= 3;
