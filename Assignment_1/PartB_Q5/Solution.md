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


### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • `N` (Total expected vehicles)<br>• `v_type` (C/B/V)<br>• `category` (F/S/G)<br>• `permit` (Y/N)<br>• `emergency` (Y/N) | 1. Input validation loop.<br>2. Faculty → Zone A (Cap: 20), Student → Zone B (Cap: 40), Visitor → Zone C (Cap: 15).<br>3. Student Van → Zone C. Visitor Van → Zone C (requires 2 spaces).<br>4. Emergency status overrides missing permit.<br>5. Update zone occupancy and counters. | • Assigned zone & remaining capacity<br>• Rejection reason (if rejected)<br>• Final summary report (total, accepted, rejected, counts by type, zone occupancies, highest occupancy zone, facility full status) | • Zone A: 20 max | Zone B: 40 max | Zone C: 15 max.<br>• Visitor Van consumes 2 parking spaces.<br>• Input validation repeats until valid input is given. |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Integer)<br>• `v_type` ('C','B','V')<br>• `category` ('F','S','G')<br>• `permit` ('Y','N')<br>• `emergency` ('Y','N') | 1. Initialize `Cap_A=20, Cap_B=40, Cap_C=15`, occupancies to 0.<br>2. **Loop `1` to `N`**:<br>&nbsp;&nbsp;&nbsp;&nbsp;a. Input and validate inputs.<br>&nbsp;&nbsp;&nbsp;&nbsp;b. Evaluate permit/emergency eligibility.<br>&nbsp;&nbsp;&nbsp;&nbsp;c. Evaluate zone eligibility & space requirement (1 space for C/B, 2 for Visitor Van).<br>&nbsp;&nbsp;&nbsp;&nbsp;d. If space exists → allocate, update occupancy & counters.<br>&nbsp;&nbsp;&nbsp;&nbsp;e. Else → reject, update reject counter.<br>3. Generate summary report after loop. | • Individual parking assignment / rejection notice<br>• Comprehensive parking summary report |
