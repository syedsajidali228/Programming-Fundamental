Name: Syed Sajid Ali

Roll No: 26k-0013

Section: BAI-1A



Question 4


Print the multiplication tables from 1 to 10, but skip the table of any number that is a multiple of

ALGORITHM:


1. Start.
   
3. Outer loop variable i runs from 1 to 10.
   
5. For eachi:
   
a. If `i % 3 == 0`, skip the table (continue to next `i`).

b. Else:

i. Output Table Heading for i.

ii. Inner loop variable `j` runs from 1 to 10.

iii. Compute product = i * j.

iv. Output `i x j = product`.

7. End..
   
   
PSEUDOCODE:

begin

for i from 1 to 10 do

if i mod 3 == 0 then

continue / skip

end if

print : multiplication table of ", i

for j from 1 to 10 do

print i, " x "j " = " (i * j)

end for

end for

end


<img width="3216" height="2440" alt="Q4_PartA" src="https://github.com/user-attachments/assets/10284582-b797-4491-9c1d-61e81bf25474" />

