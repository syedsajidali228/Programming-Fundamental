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

3. Problem Analysis Chart (PAC)
   
Given Data / Inputs	processing & Operations	Required Output	Constraints & Rules

• N (Total students)

• 5 subject marks per student (out of 100)	1. Inner loop: Read 5 marks, compute sum, check if any mark < 33.

2. Average = sm / 5.0.
   
4. Override Check: If any mark < 33 -> 'Fail - Subject Deficiency'.
   
6. If no deficiency: Avg >= 80 -> 'Distinction', Avg >= 60 -> 'Pass', Else -> 'Fail'.	• Total marks sum
   
• Calculated average

• Classification grade per student	• N students processed in outer loop.

• 5 subjects per student in inner loop.

• Passing mark per subject is 33.

• Subject deficiency overrides high average.

3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• n (integer)

• mark1, mark2, mark3, mark4, mark5 (floats/integers)	1. outer loop student =1 to n:

   a. sum = 0, deficiency = 0.
   
   b. inner loop subj = 1 to 5:
   
      - input mrks
      - sum += mark.
      - if mark < 33 then deficiency = 1.
      
   c. avg = sum / 5.0.
   
   d. if deficiency == 1 then status = 'fail - subject deficiency'
   
      else if avg >= 80 then status = 'distinction'
      else if avg >= 60 then status = 'pass'
      else status = 'fail'.	• student average
      
• classification status per student

6. Pseudocode
   
begin

    read n
    for student_count from 1 to n do
        set su_marks = 0
        set has_deficiency = 0
        
        for subj_count from 1 to 5 do
            read mark
            set sum_marks = sum_marks + mark
            if mark < 33 then
                set has_deficiency = 1
            end if
        end for
      set average = sum_marks / 5.0
        
        if has_deficiency == 1 then
           print "result: fail - subject deficiency"
        else if average >= 80 then
            print "result: distinction"
        else if average >= 60 then
            print result: pass"
        else
            print "result: fail"
        end if
    end for
end

