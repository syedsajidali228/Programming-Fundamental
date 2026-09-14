Question 3

Take a number, count how many digits it has, and state whether it is a single-digit, double-digit, or triple-digit (or more) number.

ALGORITHM:

1. Start.
   
3. Read input integer `num`.
   
5. Store absolute value `temp = abs(num)`.
   
7. Initialize `count = 0`.
   
9. If `temp == 0`, set `count = 1`.
    
11. Else, while `temp > 0`:
    
a. `temp = temp / 10`.

b. Increment `count = count + 1`.

13. Output total digit count.
    
15. Classification Decision:- If `count == 1`, print "Single-digit number".- Else if `count == 2`, print "Double-digit number".- Else (`count >= 3`), print "Triple-digit (or more) number".
    
17. End.

PSEUDOCODE:

BEGIN

READ num

set temp = abs(num)

set count = 0

if temp == 0 then

set count = 1

else

while temp > 0 do

set temp = temp / 10

set count = count + 1

end while


end if

print "total digits: ", count

if count == 1 then

print "single-digit number"

else if count == 2 then

print "double-digit number"

else

print "triple-digit (or more) number"

end if

end

Legends:
temp = Temporary Number

