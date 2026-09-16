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

### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • `v_type` (E/H)<br>• `soc`, `req_soc` (%)<br>• `duration` (hours)<br>• `time_24` (0-23)<br>• `member` (Y/N)<br>• `disabled` (Y/N)<br>• `station` (Y/N) | 1. Eligibility checks: station availability, battery SOC limits.<br>2. Priority classification (P1 Emergency, P2 Priority, P3 Normal).<br>3. Charging fee: Peak (17-22h: Rs. 50) vs Off-Peak (Rs. 35) with member discounts.<br>4. Parking fee: <=2h: 200, 2-5h: 400, >5h: 700 with free disabled parking.<br>5. Long stay warning (`duration > 8h`). | • Vehicle type & battery SOC<br>• Charging priority & peak status<br>• Charging cost & parking cost<br>• Discounts & final payable amount<br>• Long-stay warning message | • Emergency priority receives no charging discount.<br>• Hybrid qualifies only if `SOC < 40%`.<br>• Disabled status gets free parking (0 parking fee).<br>• Peak hours: 17:00 to 22:00 (5 PM to 10 PM). |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `v_type` ('E','H')<br>• `soc`, `req_soc` (Floats)<br>• `duration` (Float)<br>• `time_24` (Integer)<br>• `member`, `disabled`, `station` ('Y','N') | 1. IF `station == 'N'` OR (`v_type == 'H'` AND `soc >= 40`) OR `req_soc <= soc` → `charging_eligible = FALSE`.<br>2. Evaluate Priority: P1, P2, or P3.<br>3. Rate calculation: Peak (17-22h) = 50, Off-Peak = 35. Member discount = 10% peak, 20% off-peak (except P1).<br>4. Parking fee calculation: <=2h: 200, <=5h: 400, >5h: 700. Disabled = free, Member = 20% discount.<br>5. `Total_Payable = Final_Charging + Final_Parking`. | • Complete EV Charging & Parking Summary Invoice Receipt |
