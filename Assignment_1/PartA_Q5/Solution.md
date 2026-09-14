Question 5

Take a number, repeatedly sum its digits until the result is a single digit, and display each intermediate result. For example, if the number is 123, the sum of its digits is 6.


ALGORITHM:

1. Start.
   
3. Read integer n.
   
5. Set current = abs(n).
   
7. While current >= 10`:
   
a. Set Sum = 0, temp = current.

b. While temp > 0:

i. rem = temp % 10`.

ii. sum = sum + rem.

iii. temp = temp / 10.

c. Print intermediate result: current -> sum.

d. current = sum.

9. Output final single-digit result current.
    
11. End.
    

PSEUDOCODE:

begin

read n

set current = abs(n)

while current >= 10 do

set sum = 0

set temp = current

while temp > 0 do

set rem = temp % 10

set temp = temp / 10

end while

print ;"intermediate sum: ", current:, sum

set current = sum

end while

PRINT "final single digit: ", current

end


