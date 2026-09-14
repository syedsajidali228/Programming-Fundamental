Question 06: Smart EV Charging and Parking Management System 

1. Algorithm
   
Step 1: Start.

Step 2: Input driver parameters: Vehicle_Type ('E' or 'H'), Battery_SOC (%), Required_SOC (%), Duration (hours), Current_Time (0-23), Member_Status ('Y'/'N'), Disabled_Status ('Y'/'N'), Station_Available ('Y'/'N').

Step 3: Station & Vehicle Qualification Check:

        If Station_Available == 'N':
            If Vehicle_Type == 'H', display 'Charging unavailable. Parking only.'
            Else display 'No charging slot available.'
            Set is_charging_eligible = FALSE.
        Else:
            If Vehicle_Type == 'H' AND Battery_SOC >= 40, display 'Vehicle does not qualify for EV charging.' and set is_charging_eligible = FALSE.
            Else set is_charging_eligible = TRUE.
            
Step 4: Required Charging Check:

        If is_charging_eligible == TRUE:
            Calculate Req_Units = Required_SOC - Battery_SOC.
            If Req_Units <= 0, display 'No charging required.' and set is_charging_eligible = FALSE.
            
Step 5: Priority Category Assignment (if eligible):

        - Priority 1: If Battery_SOC <= 15 AND Required_SOC >= 80 -> Priority_Category = 'Emergency Charging Priority'.
        - Priority 2: Else if Disabled_Status == 'Y' OR (Member_Status == 'Y' AND Battery_SOC <= 30) -> Priority_Category = 'Priority Charging'.
        - Priority 3: Else -> Priority_Category = 'Normal Charging'.
        
Step 6: Calculate Electricity Charging Fee:

        Determine Peak status: If Current_Time >= 17 AND Current_Time < 22 -> Rate = Rs. 50 (Peak); else Rate = Rs. 35 (Off-Peak).
        Base_Charge = Req_Units * Rate.
        Charging_Discount = 0.
        If Priority_Category != 'Emergency Charging Priority' AND Member_Status == 'Y':
            If Peak -> Charging_Discount = 0.10 * Base_Charge.
            Else -> Charging_Discount = 0.20 * Base_Charge.
        Final_Charging_Cost = Base_Charge - Charging_Discount.
        
Step 7: Calculate Parking Fee:

        If Duration <= 2 -> Base_Parking = 200.
        Else if Duration <= 5 -> Base_Parking = 400.
        Else -> Base_Parking = 700.
        Parking_Discount = 0.
        If Disabled_Status == 'Y':
            Parking_Discount = Base_Parking (Free Parking).
        Else if Member_Status == 'Y':
            Parking_Discount = 0.20 * Base_Parking.
        Final_Parking_Cost = Base_Parking - Parking_Discount.
        
Step 8: Calculate Total Payable = Final_Charging_Cost + Final_Parking_Cost.

Step 9: Long Stay Warning Check: If Duration > 8, display 'Long-stay warning: Please relocate your vehicle after charging.' else 'Standard parking duration.'

Step 10: Display complete itemized invoice.

Step 11: End.

3. Problem Analysis Chart (PAC)

Given Data / Inputs	Processing & Operations	Required Output	Constraints & Rules

• vehicle type (e/h)

• battery soc%

• required soc%

• duration (hours)

• current time (0-23)

• member (y/n)

• disabled (y/n)
• station available (y/n)	1. eligibility checks: station availability, soc limits.

2. priority classification (p1, p2, p3).
3. 
4. charging cost: peak (17-22h: rs.50) vs off-peak (rs.35) with member discounts.
5. 
6. parking cost: <=2h: 200, 2-5h: 400, >5h: 700 with free disabled parking.
7. 
8. long stay warning (>8h).	• vehicle type & battery soc
   
• charging cost & parking cost

• discounts & final payable amount

• long-stay warning message	• emergency priority gets no charging discount.

• hybrid qualifies only if soc < 40%.

• disabled gets free parking (0 parking fee).

• peak hours: 17:00 to 22:00.

3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• type ('E','H')

• soc, req_soc (Floats)

• duration (Float)

• time (Integer)

• member, disabled, station ('Y','N')	1. IF station=='N' OR (type=='H' AND soc>=40) OR req_soc<=soc -> charging_eligible = FALSE.

2. IF P1 (soc<=15 AND req_soc>=80) -> 'Emergency charging priority'.
   
   Else if p2 (disabled=='y' or (member=='y' and soc<=30)) -> 'priority charging'.
   
   Else -> 'normal charging'.
   
4. Charging rate: peak (17-22h)=50, off-peak=35. Member discount: 10% peak, 20% off-peak (except P1).
   
6. Parking fee: <=2h:200, <=5h:400, >5h:700. Disabled=0, Member=20% off.
   
8. Final = Charging + Parking.	• Complete EV Charging & Parking Summary Invoice
   


 
5. Pseudocode
   
begin

    read v_type, soc, req_soc, duration, time_24, member, disabled, station
    
    set is_charging_eligible = true
    if station == 'n' then
        if v_type == 'h' then
            print "charging unavailable. parking only."
        else
            print "no charging slot available."
        end if
        set is_charging_eligible = false
    else
        if v_type == 'h' and soc >= 40 then
            print "vehicle does not qualify for ev charging."
            set is_charging_eligible = false
        end if
    end if
    
    set final_charging_cost = 0.0
    if is_charging_eligible == true then
        set req_units = req_soc - soc
        if req_units <= 0 then
            print "no charging required."
        else
            // priority classification
            if soc <= 15 and req_soc >= 80 then
                set priority = "emergency charging priority"
            else if disabled == 'y' or (member == 'y' and soc <= 30) then
                set priority = "priority charging"
            else
                set priority = "normal charging"
            end if
            
            // rate calculation
            if time_24 >= 17 and time_24 < 22 then
                set rate = 50.0
                set is_peak = true
            else
                set rate = 35.0
                set is_peak = false
            end if
            
            set base_charging = req_units * rate
            set charging_discount = 0.0
            if priority != "emergency charging priority" and member == 'y' then
                if is_peak then
                    set charging_discount = 0.10 * base_charging
                else
                    set charging_discount = 0.20 * base_charging
                end if
            end if
            set final_charging_cost = base_charging - charging_discount
        end if
    end if
    
    // parking calculation
    if duration <= 2 then
        set base_parking = 200.0
    else if duration <= 5 then
        set base_parking = 400.0
    else
        set base_parking = 700.0
    end if
    
    set parking_discount = 0.0
    if disabled == 'y' then
        set parking_discount = base_parking
    else if member == 'y' then
        set parking_discount = 0.20 * base_parking
    end if
    set final_parking_cost = base_parking - parking_discount
    
    set total_payable = final_charging_cost + final_parking_cost
    
    print "=== ev invoice receipt ==="
    print "total payable amount: rs. ", total_payable
    if duration > 8 then
        print "long-stay warning: please relocate your vehicle after charging."
    else
        print "standard parking duration."
    end if
end

