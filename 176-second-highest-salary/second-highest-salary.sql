# Write your MySQL query statement below
SELECT(SELECT DISTINCT Salary 
FROM Employee
order by Salary desc
limit 1 offset 1)as SecondHighestSalary;