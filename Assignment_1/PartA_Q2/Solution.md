Question 2

Input a year and determine whether it is a leap year. (Rule: divisible by 4 AND (not divisible by 100 OR divisible by 400).)

ALGORITHM:

1. Start
2.input Y (Year)
3. condition (Y% 4 == 0) AND (Y % 100!= 0 OR Y %400 ==0).
4 If condition is TRUE, output "Y is a Leap Year".
5. Else (condition is FALSE), output "Y is not a Leap Year".
6 End..	



Pseudocode:

begin,

read year

if (year% 4 == 0 and (year %100 != 0 or year % 400 == 0)) then

print year, " is a leap year"

else

print year," is not a leap year"

end if

end.

