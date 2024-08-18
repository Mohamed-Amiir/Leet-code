SELECT st.student_id, st.student_name,sb.subject_name ,COUNT(ex.student_id) as attended_exams
FROM Students st
CROSS JOIN Subjects sb
LEFT JOIN Examinations ex
ON ex.student_id = st.student_id AND ex.subject_name = sb.subject_name
GROUP BY st.student_id,st.student_name, sb.subject_name
ORDER BY st.student_id ASC ,sb.subject_name ASC
