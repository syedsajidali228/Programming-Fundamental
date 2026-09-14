Question 02: Elevator Simulation

1. Algorithm
   
Step 1: Start.

Step 2: Initialize current_floor = 0 (elevator starts at ground floor).

Step 3: Read total number of floor requests N (e.g., N = 5).

Step 4: Set loop counter i = 1.

Step 5: If i > N, go to Step 12 (exit loop).

Step 6: Read requested_floor for request i.

Step 7: Check floor comparison:

        If requested_floor > current_floor, print 'Moving Up'.
        Else if requested_floor < current_floor, print 'Moving Down'.
        Else (requested_floor == current_floor), print 'Doors Opening'.
        
Step 8: Update current_floor = requested_floor.

Step 9: Increment loop counter i = i + 1.

Step 10: Go to Step 5.

Step 11: End.

3. Problem Analysis Chart (PAC)
   
Given Data / Inputs	Processing & Operations	Required Output	Constraints & Rules

• Initial floor = 0

• N (Total requests)

• requested_floor (for each request)	1. For each request, compare requested_floor with current_floor.

2. If requested > current -> Print 'Moving Up'.
   
4. If requested < current -> Print 'Moving Down'.
   
6. If requested == current -> Print 'Doors Opening'.
   
8. Update current_floor = requested_floor after each stop.	• Direction message for each stop ('Moving Up', 'Moving Down', or 'Doors Opening')
   
• Updated current_floor status	• Elevator starts at Floor 0.

• Process requests sequentially one by one in a loop.

• List of N requests (e.g., 3, 1, 5, 2, 2).


3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• N (Integer, number of requests)

• requested_floor (Integer sequence)	1. Set current_floor = 0.

2. Loop i from 1 to N:
   
   a. Read requested_floor.
   
   b. IF requested_floor > current_floor -> Output 'Moving Up'.
   
   c. ELSE IF requested_floor < current_floor -> Output 'Moving Down'.
   
   d. ELSE -> Output 'Doors Opening'.
   
   e. Set current_floor = requested_floor.	• Status string per request: 'Moving Up', 'Moving Down', or 'Doors Opening'
   
 
6. Pseudocode
   
begin

    set current_floor= 0
    read n
    for i from 1 to n do
        read requested_floor
       if requested_floor > current_floor then
            print "moving up"
        else if requested_floor < current_floor then
            print "moving down"
        else
            print "doors opening"
        end if
        set current_floor = requested_floor
    end for
end

