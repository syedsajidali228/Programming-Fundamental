Question 05: Smart Campus Parking and Access Management System

1. Algorithm
   
Step 1: Start.

Step 2: Initialize Zone Capacities and Occupancy:

        Cap_A = 20, Occ_A = 0; Cap_B = 40, Occ_B = 0; Cap_C = 15, Occ_C = 0.
        Set count_cars = 0, count_bikes = 0, count_vans = 0, count_accepted = 0, cont_rejected = 0.
        
Step 3: Read total vehicles to process N.

Step 4: Set loop counter i = 1.

Step 5: If i > N, go to Step 14 (exit loop).

Step 6: Input Vehicle_Type ('C', 'B', 'V'), User_Category ('F', 'S', 'G'), and Valid_Permit ('Y', 'N')

Step 7: Validation Loop: If values are invalid, prompt user to re-enter until valid inputs are received.

Step 8: Emergency Check: If Valid_Permit == 'N', ask if Emergency_Vehicle ('Y', 'N'). If 'N', reject vehicle and go to Step 12.

Step 9: Zone Assignment & Capacity Verification:

        - Faculty ('F'): Check Zone A capacity (1 space for C/B, 1 space for V if space available).
        - Student ('S'): Check Zne B capacity (1 space for C/B). If Van ('V'), redirect to Zone C if space available.
        - Visitor ('G'): Check Zone C capacity (1 space for C/B; 2 spaces for V if at least 2 spaces available).
        
Step 10: Processing Outcome:

        If suitable zone space is available:
            Update Zone Occupancy (Occ_A, Occ_B, or Occ_C).
            Increment count_accepted, and appropriate vehicle counter (count_cars, count_bikes, or count_vans).
            Display assigned zone and remaining capacity.
        Else:
            Increment count_rejected.
            Display rejection reason ('No space available' or 'No suitable zone').
            
Step 11: Increment loop counter i = i + 1.

Step 12: Go to Step 5

Step 13: Generate Parking Summary Report:

        Display Total Processed (N), Total Accepted, Total Rejected, counts of Cars/Bikes/Vans parked.
        Display final occupancy and remaining capacity for Zone A, Zone B, Zone C.
        Determine and display zone with highest occupancy percentage.
        Display whether entire facility is FULL (Occ_A==20 AND Occ_B==40 AND Occ_C==15).
        
Step 14: End.

3. Problem Analysis Chart (PAC)
   
Given Data / Inputs	Processing & Operations	Required Output	Constraints & Rules

• n (total expected vehicles)

• vehicle type (c/b/v)

• user category (f/s/g)

• valid permit (y/n)

• emergency status (y/n)	1. repeated validation loop.

2. rules: faculty->zone a (cap 20), student->zone b (cap 40), visitor->zone c (cap 15).
   
4. vn rules: faculty van->zone a if space; student van->zone c if space; visitor van->zone c if >=2 spaces free.
   
6. emergency override allows entry regardless of permit.
   
8. capacity updates & counter increments.	• assigned zone & remaining capacity
   
• rejection reason (if rejected)

• final summary: total processed, accepted, rejected, counts by type, zone occupancies, highest occupancy zone, facility full status.	• zone a: 20 max, zone b: 40 max, zone c: 15 max.

• visitor van consumes 2 spaces.

• input validation repeat until valid.

3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• n (integer)

• type ('c','b','v')

• category ('f','s','g')

• permit ('y','n')

• emergency ('y','n')	1. initialize cap_a=20, cap_b=40, cap_c=15, occ_a=occ_b=occ_c=0.

2. loop 1 to n:
   
   a. input & validate type, category, permit.
   
   b. evaluate zone eligibility & space requirement (1 space for c/b, 2 for c-van).
   
   c. if space exists -> allocate, occ+=spaces, increment type counter.
   
   d. else -> reject, increment reject counter.
   
4. compute highest occupancy zone & full status.	• individual parking assignment / rejection notice
   
• comprehensive parking summary report


 
7. Pseudocode
   
begin

    set cap_a = 20, occ_a = 0
    set cap_b = 40, occ_b = 0
    set ca_c = 15, occ_c = 0
    set count_cars = 0, count_bikes = 0, count_vans = 0
    set count_accepted = 0, count_rejected = 0
    
    read n
    for i from 1 to n do
        // input validation loop
        repeat
            read v_type, category, permit
        until v_type in ['c','b','v'] and category in ['f','s','g'] and permit in ['y','n']
        
        set is_allowed = false
        if permit == 'n' then
            reademergency
            if emergency == 'y' then
                set is_allowed = true
            end if
        else
            set is_allowed = true
        end if
        
        if is_allowed == false then
            print "rejected: invalid permit"
            set count_rejected = count_rejected + 1
        else
            // zone allocation logic
            if category == 'f' then
                if occ_a < cap_a then
                    set occ_a = occ_a + 1
                    set count_accepted = count_accepted + 1
                    print "assigned: zone a. remaining: ", (cap_a - occ_a)
                else
                    print "rejected: zone a full"
                    set count_rejected = count_rejected + 1
                end if
            else if category == 's' then
                if v_type == 'v' then
                    if occ_c < cap_c then
                        set occ_c = occ_c + 1
                        set count_accepted = count_accepted + 1
                        print "assigned: zon c (student van). remaining: ", (cap_c - occ_c)
                    else
                        print "rejected: zone c full for student van"
                        set count_rejected = count_rejected + 1
                    end if
                else
                    if occ_b < cap_b then
                        set occ_b = occ_b + 1
                        set count_accepted= count_accepted + 1
                        print "assigned: zone b. remaining: ", (cap_b - occ_b)
                    else
                        print "rejected: zone b full"
                        set count_rejected = count_rejected + 1
                    end if
                end if
            else if category == 'g' then
                set space_req = 1
                if v_type == 'v' then set space_req = 2 end if
                if (cap_c - occ_c) >= space_req then
                    set occ_c = occ_c + space_req
                    set count_accepted = count_accepted + 1
                    print "assigned: zone c. remaining: ", (cap_c - occ_c)
                else
                    print "rejected: insufficient space in zone c"
                    set count_rejected = count_rejected + 1
                end if
            end if
        end if
    end for
    
    print "=== parking summary report ==="
    print "total processed ", n, " | accepted: ", count_accepted, " | rejected: ", count_rejected
end

