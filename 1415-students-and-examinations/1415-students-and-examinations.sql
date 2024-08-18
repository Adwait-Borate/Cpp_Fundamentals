WITH cte1 AS
(
    SELECT student_id, subject_name, COUNT(subject_name) AS attnd
    FROM Examinations
    GROUP BY student_id, subject_name
),
cte2 AS
(
    SELECT * 
    FROM Students
    CROSS JOIN Subjects
)

SELECT 
    cte2.student_id, 
    cte2.student_name, 
    cte2.subject_name, 
    CASE 
        WHEN cte1.attnd IS NOT NULL THEN cte1.attnd 
        ELSE 0 
    END AS attended_exams
FROM cte2 
LEFT JOIN cte1
ON cte1.student_id = cte2.student_id AND cte1.subject_name = cte2.subject_name
ORDER BY cte2.student_id, cte2.subject_name;
