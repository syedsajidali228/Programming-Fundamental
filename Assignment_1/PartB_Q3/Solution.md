Question 03: Class Result Processing

1. Algorithm
   
Step 1: Start.

Step 2: Read total number of students N (N = 3).

Step 3: Set outer loop counter student_count = 1.

Step 4: If student_count > N, go to Step 18 (exit outer loop).

Step 5: Initialize sum_marks = 0, has_deficiency = 0.

Step 6: Set inner loop counter subj_count = 1.

Step 7: f subj_count > 5, go to Step 12 (exit inner loop).

Step 8: Read mark for suject subj_count.

Step 9: Add mark to sum_marks (sum_marks = sum_marks + mark).

Step 10: If mark < 33, set has_deficiency = 1.

Step 11: Increment subj_count = subj_count + 1, go to Step 7.

Step 12: Compute average = sum_marks / 5.0.

Step 13: Determine student classification:

        If has_deficiency == 1, result = 'Fail - Subject Deficiency'.
        Else if average >= 80, reult = 'Distinction'.
        Else if average >= 60, result = 'Pass'.
        Else, result = 'Fail'.

Step 14: Display Student ID, average, and final result.

Step 15: Increment student_count = student_count + 1.

Step 16: Go to Step 4.

Step 17: End.


### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • `N` (Total students)<br>• 5 subject marks per student (out of 100) | 1. Inner loop: Read 5 marks, compute sum, check if any mark < 33.<br>2. `Average = sum_marks / 5.0`.<br>3. Override Check: If any `mark < 33` → "Fail — Subject Deficiency".<br>4. If no deficiency: `Avg >= 80` → "Distinction", `Avg >= 60` → "Pass", Else → "Fail". | • Total marks sum<br>• Calculated average<br>• Classification grade per student | • `N` students processed in outer loop.<br>• 5 subjects per student in inner loop.<br>• Passing mark per subject is 33.<br>• Subject deficiency overrides high average. |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Integer)<br>• `mark1, mark2, mark3, mark4, mark5` (Integers) | 1. **Outer loop `student` = 1 to `N`**:<br>&nbsp;&nbsp;&nbsp;&nbsp;a. `sum = 0`, `deficiency = 0`.<br>&nbsp;&nbsp;&nbsp;&nbsp;b. **Inner loop `subj` = 1 to 5**:<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Read `mark`.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- `sum += mark`.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- IF `mark < 33` THEN `deficiency = 1`.<br>&nbsp;&nbsp;&nbsp;&nbsp;c. `avg = sum / 5.0`.<br>&nbsp;&nbsp;&nbsp;&nbsp;d. IF `deficiency == 1` THEN `status = "Fail — Subject Deficiency"`<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF `avg >= 80` THEN `status = "Distinction"`<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF `avg >= 60` THEN `status = "Pass"`<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE `status = "Fail"`. | • Student average<br>• Classification status per student |
