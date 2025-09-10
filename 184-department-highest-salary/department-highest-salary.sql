# Write your MySQL query statement below
SELECT d.Name AS Department, e.Name AS Employee, e.Salary
FROM Employee e
JOIN Department d ON e.DepartmentId = d.Id
WHERE e.Salary = (
    SELECT MAX(Salary)
    FROM Employee
    WHERE DepartmentId = e.DepartmentId
);
