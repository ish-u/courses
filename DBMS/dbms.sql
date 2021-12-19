CREATE SCHEMA COMPANYDB;
USE COMPANYDB;

-- EMPLOYEE TABLE
CREATE TABLE EMPLOYEE(
    ENO CHAR(3),
    ENAME VARCHAR(50) NOT NULL,
    JOB_TYPE VARCHAR(50) NOT NULL,
    MANAGER CHAR(3),
    HIRE_DATE DATE NOT NULL,
    DNO INT,
    COMMISSION DECIMAL(10,2),
    SALARY DECIMAL(7,2) NOT NULL,
    PRIMARY KEY(ENO)
);

-- DEPARTMENT TABLE
CREATE TABLE DEPARTMENT(
	DNO INT NOT NULL,
    DNAME VARCHAR(50),
    LOCATION VARCHAR(50) DEFAULT 'New Delhi',
    PRIMARY KEY(DNO)
);


-- POPULATING DEPARTMENT TABLE
INSERT INTO DEPARTMENT(DNO,DNAME,LOCATION) VALUES
	(1,'Research','Chennai'),
    (2,'Adminstration','New Delhi'),
    (7,'Headquaters','New Delhi');

-- POPULATING EMPLOYEE TABLE
INSERT INTO EMPLOYEE VALUES
	(001, 'Georgi Facello' , 'Senior Engineer' , NULL, '1986-06-26', 1, 580, 60117 ),
    (911, 'Shay Casley' , 'Senior Engineer' , NULL, '1988-06-25', 1, 555, 66074 ),
    (667, 'Makato Cusworth' , 'Senior Staff' , NULL, '1990-06-25', 2, 736, 66961 ),
    (004, 'Chirstian Koblick', 'Engineer', NULL, '1986-12-01', 1, NULL, 40054),
    (339, 'Tenius Liedekerke', 'Engineer', NULL, '1989-11-30', 1, 200, 46065),
    (005, 'Kyoichi Maliniak', 'Staff', NULL, '1989-09-12', 2, NULL, 58326),
    (882, 'Fun Heuser' , 'CEO', NULL, '1994-11-29' ,7 ,1500, 78228 );


-- ASSIGNING MANAGER
UPDATE EMPLOYEE SET MANAGER=667 WHERE JOB_TYPE = 'Staff';
UPDATE EMPLOYEE SET MANAGER=001 WHERE JOB_TYPE = 'Engineer';
UPDATE EMPLOYEE SET MANAGER=882 WHERE JOB_TYPE = 'Senior Engineer';
UPDATE EMPLOYEE SET MANAGER=882 WHERE JOB_TYPE = 'Senior Staff';

-- ALTERING THE CREATED TABLE TO ADD FOREIGN KEYS
ALTER TABLE EMPLOYEE ADD FOREIGN KEY(DNO) REFERENCES DEPARTMENT(DNO); 
ALTER TABLE EMPLOYEE ADD FOREIGN KEY(MANAGER) REFERENCES EMPLOYEE(ENO);


-- 1. Query to display Employee Name, Job, Hire Date, Employee Number; for each employee
-- with the Employee Number appearing first.
SELECT ENO,ENAME,JOB_TYPE,HIRE_DATE
FROM EMPLOYEE;

-- 2. Query to display unique Jobs from the Employee Table.
SELECT DISTINCT JOB_TYPE 
FROM EMPLOYEE;

-- 3. Query to display the Employee Name concatenated by a Job separated by a comma.
SELECT CONCAT_WS(' , ',ENAME,JOB_TYPE) AS NAME_JOB 
FROM EMPLOYEE;

-- 4. Query to display all the data from the Employee Table. Separate each Column by a comma
SELECT CONCAT_WS(' , ',ENO,ENAME,JOB_TYPE,MANAGER,HIRE_DATE,DNO,COMMISSION,SALARY) AS THE_OUTPUT 
FROM EMPLOYEE;

-- 5. Query to display the Employee Name and Salary of all the employees earning more than
-- $2850.
SELECT ENAME, SALARY 
FROM EMPLOYEE 
WHERE EMPLOYEE.SALARY > 45550;

-- 6. Query to display Employee Name and Department Number for the Employee No= 79
SELECT ENAME,DNO 
FROM EMPLOYEE 
WHERE ENO = 667;

-- 7. Query to display Employee Name and Salary for all employees whose salary is not in the
-- range of $1500 and $2850.
SELECT ENAME, SALARY 
FROM EMPLOYEE 
WHERE SALARY > 40000 AND SALARY < 60000;

# 8. Query to display Employee Name and Department No. of all the employees in Dept 10 and
# Dept 30 in the alphabetical order by name
SELECT ENAME,DNO
FROM EMPLOYEE
WHERE DNO = 1 OR DNO = 7
ORDER BY ENAME;

# 9. Query to display Name and Hire Date of every Employee who was hired in 1981.
SELECT ENAME,HIRE_DATE
FROM EMPLOYEE
WHERE HIRE_DATE LIKE '1986______';

# 10. Query to display Name and Job of all employees who have not assigned a supervisor.
SELECT ENAME, JOB_TYPE
FROM EMPLOYEE
WHERE MANAGER IS NULL;

-- 11. Query to display the Name, Salary and Commission for all the employees who earn
-- commission
SELECT ENAME,SALARY,COMMISSION 
FROM EMPLOYEE 
WHERE COMMISSION IS NOT NULL;

# 12. Sort the data in descending order of Salary and Commission
SELECT *
FROM EMPLOYEE
ORDER BY SALARY DESC, COMMISSION DESC;

-- 13. Query to display Name of all the employees where the third letter of their name is ‘A’.
SELECT ENAME 
FROM EMPLOYEE 
WHERE ENAME LIKE '__A%';

-- 14. Query to display Name of all employees either have two ‘R’s or have two ‘A’s in their
-- name and are either in Dept No = 30 or their Manger’s Employee No = 7788.
SELECT * FROM EMPLOYEE 
WHERE (ENAME LIKE '%AA%' OR '%RR%') AND (DNO = 30 OR MANAGER = 7788);

# 16. Query to display the Current Date along with the day name.
SELECT DATE(NOW()) AS 'DATE',DAYNAME(NOW()) AS 'DAY';

# 17. Query to display Name, Hire Date and Salary Review Date which is the 1st Monday after
# six months of employment.

SELECT ENAME, HIRE_DATE,
    DATE_ADD((DATE_ADD(HIRE_DATE, INTERVAL 6 MONTH )), INTERVAL 
    IF(WEEKDAY(DATE_ADD(HIRE_DATE, INTERVAL 6 MONTH )) = 0,0,7 - WEEKDAY(DATE_ADD(HIRE_DATE, INTERVAL 6 MONTH ))) DAY) 
    AS 'REVIEW DATE'
FROM EMPLOYEE;

/* # 18. Query to display Name and calculate the number of months between today and the date
# on which employee was hired of department ‘Purchase’.
SELECT ENAME, ROUND(DATEDIFF(NOW(), HIRE_DATE) / 30) AS 'MONTHS WORKING'
FROM EMPLOYEE
WHERE DNO IN (SELECT DNO FROM DEPARTMENT WHERE DNAME='Research');
 */


# 21. Query to display Name, Hire Date and Day of the week on which the employee started.
SELECT ENAME,HIRE_DATE,DAYNAME(HIRE_DATE) AS DAY
FROM EMPLOYEE;

-- 22. Query to display Name, Department Name and Department No for all the employees
SELECT E.ENAME,D.DNAME,D.DNO
FROM EMPLOYEE AS E JOIN DEPARTMENT AS D
ON E.DNO = D.DNO;

-- 23. Query to display Unique Listing of all Jobs that are in Department number 30.
SELECT DISTINCT E.JOB_TYPE FROM EMPLOYEE AS E WHERE E.DNO = 1;

-- 24. Query to display Name, Dept Name of all employees who have an ‘A’ in their name.
SELECT E.ENAME,D.DNAME 
FROM EMPLOYEE AS E JOIN DEPARTMENT AS D ON E.DNO = D.DNO
WHERE E.ENAME LIKE '%A%';

-- 25. Query to display Name, Job, Department No. And Department Name for all the
-- employees working at the New Delhi location.
SELECT E.ENO,E.ENAME,E.JOB_TYPE,E.DNO,D.DNAME
FROM EMPLOYEE AS E JOIN DEPARTMENT AS D ON E.DNO = D.DNO
WHERE D.LOCATION = 'New Delhi';


# 26. Query to display Name and Employee no. Along with their Manger’s Name and the
# Manager’s employee no; along with the Employees’ Name who do not have a Manager.
SELECT E.ENO,E.ENAME,S.ENO,S.ENAME
FROM EMPLOYEE AS E LEFT JOIN EMPLOYEE AS S on E.MANAGER = S.ENO;

# 27. Query to display Name, Dept No. And Salary of any employee whose department No. and
# salary matches both the department no. And the salary of any employee who earns a
# commission.
SELECT ENAME,DNO,SALARY
FROM EMPLOYEE E
WHERE COMMISSION IN (SELECT COMMISSION FROM EMPLOYEE WHERE E.DNO = DNO AND E.SALARY = SALARY);

#28. Query to display Name and Salaries represented by asterisks, where each asterisk (*)
# signifies $100.
SELECT ENAME,CONCAT(CONVERT(SALARY/100,UNSIGNED INTEGER),'*')
AS SALARY
FROM EMPLOYEE;

# 29. Query to display the Highest, Lowest, Sum and Average Salaries of all the employees
SELECT 
MAX(SALARY) AS HIGHEST, 
MIN(SALARY) AS LOWEST,
AVG(SALARY) AS AVERAGE,
SUM(SALARY) AS SUM
FROM EMPLOYEE;

# 30. Query to display the number of employees performing the same Job type functions.
SELECT JOB_TYPE,COUNT(*) AS NUMBER_OF_EMPLOYEE 
FROM EMPLOYEE
GROUP BY JOB_TYPE;

# 31. Query to display the no. of managers without listing their names.
SELECT COUNT(*) AS NO_OF_MANAGERS
FROM EMPLOYEE
WHERE ENO IN (SELECT DISTINCT MANAGER FROM EMPLOYEE);

# 32. Query to display the Department Name, Location Name, No. of Employees and the average
# salary for all employees in that department.
WITH SALARY_TABLE(DNO,AVERAGE_SALARY,NO_OF_EMPLOYEE) AS
    (
        SELECT DNO,AVG(SALARY),COUNT(*)
        FROM EMPLOYEE
        GROUP BY DNO
    )
SELECT D.*,S.NO_OF_EMPLOYEE,S.AVERAGE_SALARY
FROM DEPARTMENT AS D JOIN SALARY_TABLE AS S
ON D.DNO = S.DNO;

# 33. Query to display Name and Hire Date for all employees in the same dept. as Blake.
SELECT ENAME,HIRE_DATE
FROM EMPLOYEE
WHERE DNO IN (
    SELECT E.DNO
    FROM EMPLOYEE AS E
    WHERE E.ENAME LIKE '%Shay%'
);


# 34. Query to display the Employee No. And Name for all employees who earn more than the
# average salary.
SELECT E.ENO,E.ENAME
FROM EMPLOYEE AS E
WHERE E.SALARY > (SELECT AVG(SALARY) FROM EMPLOYEE);

# 35. Query to display Employee Number and Name for all employees who work in a department
# with any employee whose name contains a ‘T’
SELECT E.ENO,E.ENAME
FROM EMPLOYEE AS E
WHERE E.DNO IN (
    SELECT DISTINCT DNO
    FROM EMPLOYEE
    WHERE ENAME LIKE '%T%'
);


# 36. Query to display the names and salaries of all employees who report to supervisor named
# ‘Fun’
SELECT E.ENAME,E.SALARY
FROM EMPLOYEE AS E
WHERE E.MANAGER IN (SELECT ENO FROM EMPLOYEE WHERE ENAME LIKE '%Fun%');

# 37. Query to display the department no, name and job for all employees in the Adminstration
# department
SELECT E.DNO,E.ENAME,E.JOB_TYPE
FROM EMPLOYEE AS E
WHERE E.DNO IN (SELECT DNO FROM DEPARTMENT WHERE DNAME='Adminstration');

# 38. Display names of employees along with their department name who have more than 20
# years experience
SELECT E.ENAME,D.DNAME,E.HIRE_DATE,
        ROUND(DATEDIFF(NOW(),E.HIRE_DATE)/365) AS YEARS_EXP
FROM EMPLOYEE AS E JOIN DEPARTMENT AS D ON E.DNO = D.DNO
WHERE ROUND(DATEDIFF(NOW(),HIRE_DATE)/365) > 20;

# 39. Display total number of departments at each location
SELECT LOCATION,COUNT(*) AS NO_OF_DEPARTMENT
FROM DEPARTMENT
GROUP BY LOCATION;

# 40. Find the department name in which at least 20 employees work in.
SELECT D.DNAME
FROM DEPARTMENT AS D
WHERE D.DNO IN (
    SELECT DNO
    FROM EMPLOYEE
    GROUP BY DNO
    HAVING COUNT(*) > 2
);

# 41. Query to find the employee’ name who is not supervisor and name of supervisor
# supervising more than 5 employees
WITH SUPERVISOR(ENO) AS (
    SELECT ENO
    FROM EMPLOYEE
    WHERE ENO IN (SELECT E.MANAGER FROM EMPLOYEE AS E)
)
(
    SELECT E.ENO,E.ENAME
    FROM EMPLOYEE AS E
    WHERE E.ENO NOT IN (SELECT ENO FROM SUPERVISOR)
)
UNION
(
    SELECT E.ENO, E.ENAME
    FROM EMPLOYEE AS E,
         SUPERVISOR AS S
    WHERE E.MANAGER = S.ENO
    GROUP BY S.ENO
    HAVING COUNT(*) > 2
);
# 42. Query to display the job type with maximum and minimum employees
WITH JOB(JOB_TYPE,NO) AS
    (SELECT JOB_TYPE,COUNT(*)
    FROM EMPLOYEE
    GROUP BY JOB_TYPE)
SELECT JOB_TYPE,NO
FROM JOB
WHERE NO >= (SELECT MAX(NO) FROM JOB)
UNION
SELECT JOB_TYPE,NO
FROM JOB
WHERE NO >= (SELECT MIN(NO) FROM JOB);
