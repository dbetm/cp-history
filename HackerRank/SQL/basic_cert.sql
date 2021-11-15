SELECT e.employee_id, e.name FROM employee_information as e
JOIN last_quarter_bonus as lqb
ON lqb.employee_id = e.employee_id
WHERE lqb.bonus >= 5000 AND e.division = 'HR';


SELECT cu.customer_id, cu.name,
CONCAT('+', cc.country_code, cu.phone_number)
FROM customers as cu
INNER JOIN country_codes as cc
ON cc.country = cu.country
ORDER BY cu.customer_id;
