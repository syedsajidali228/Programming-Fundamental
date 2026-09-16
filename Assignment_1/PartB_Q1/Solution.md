Question 01: Hotel Booking System

1. Algorithm
   
Step 1: Start.

Step 2: Initialize Total_Hotel_Revenue = 0.0.

Step 3: Read total number of guests N (e.g., N = 4).

Step 4: Set loop counter i = 1.

Step 5: If i > N, go to Step 16 (exit loop).

Step 6: Read Season ('Peak' or 'Off-Peak'), Room_Type ('Standard', 'Deluxe', or 'Suite'), and Nights_Stayed.

Step 7: Check Season condition:

        If Season == 'Peak':
        
            If Room_Type == 'Standard', set Base_Rate = 5000.
            
            Else if Room_Type == 'Deluxe', set Base_Rate = 8000.
            
            Else if Room_Type == 'Suite', set Base_Rate = 12000.
            
        Else if Season == 'Off-Peak':
        
            If Room_Type == 'Standard', set Base_Rate = 3000.
            
            Else if Room_Type == 'Deluxe', set Base_Rate = 5000.
            
            Else if Room_Type == 'Suite', set Base_Rate = 8000.
            
Step 8: Calculate Gross_Amount = Base_Rate * Nights_Stayed.

Step 9: Initialize Discount = 0.0.

Step 10: If Nights_Stayed > 7, set Discount = 0.15 * Gross_Amount.

Step 11: Calculate Guest_Final_Price = Gross_Amount - Discount.

Step 12: Display Guest_Final_Price for Guest i.

Step 13: Update Total_Hotel_Revenue = Total_Hotel_Revenue + Guest_Final_Price.

Step 14: Increment loop counter i = i + 1.

Step 15: Go to Step 5.

Step 16: Display Total_Hotel_Revenue.

Step 17: End.


3. Problem Analysis Chart (PAC)
4. 
Given Data / Inputs	Processing & Operations	Required Output	Constraints & Rules

• N (Total Guests)

• Season (Peak/Off-Peak)

• Room Type (Standard/Deluxe/Suite)

• Nights Stayed	1. Base rate selection via nested season & room type check.

2. Gross = Base Rate × Nights.
3. 
4. Discount = 15% of Gross if Nights > 7; else 0.
5. 
6. Guest Price = Gross - Discount.
7. 
8. Total Revenue = ∑ Guest Price.	• Individual Guest Final Price
9. 
• Total Hotel Revenue	• Loop executes for N guests.

• Peak Rates: Standard=5000, Deluxe=8000, Suite=12000.

• Off-Peak Rates: Standard=3000, Deluxe=5000, Suite=8000.

• 15% discount strictly for Nights > 7.


3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• N (Integer)

• Season (String)

• Room_Type (String)

• Nights_Stayed (Integer)	1. Loop i from 1 to N:

   a. Input Season, Room_Type, Nights.
   
   b. Determine Base_Rate based on Season and Room_Type.
   
   c. Compute Gross = Base_Rate * Nights.
   
   d. If Nights > 7, Discount = 0.15 * Gross; else 0.
   
   e. Guest_Price = Gross - Discount.
   
   f. Total_Revenue += Guest_Price.
   
2. Output Total_Revenue after loop.	• Guest_Final_Price (for each guest)

   
   5. pseudocode:
      
begin

    set total_hotel_revenue = 0
    
    read n
    
    for i from 1 to n do
    
        read season, room_type, nights_stayed
        
        
        if season == "peak" then
            if room_type == "standard" then
                set base_rate = 5000
            else if room_type == "deluxe" then
                set base_rate = 8000
            else if room_type == "suite" then
                set base_rate = 12000
            end if
        else if season == "off-peak" then
            if room_type == "standard" then
                set base_rate = 3000
            else if room_type == "deluxe" then
                set base_rate = 5000
            else if room_type == "suite" then
                set base_rate = 8000
            end if
        end if
        
        set gross_amount = base_rate * nights_stayed
        
        if nights_stayed > 7 then
            set discount = 0.15 * gross_amount
        else
            set discount = 0.0
        end if
      set guest_final_price = gross_amount - discount
        print "guest ", i, " total price: rs. ", guest_final_price
        set total_hotel_revenue = total_hotel_revenue + guest_final_price
    end for

• Total_Hotel_Revenue (final total)


### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • `N` (Total Guests)<br>• `Season` (Peak/Off-Peak)<br>• `Room_Type` (Standard/Deluxe/Suite)<br>• `Nights_Stayed` | 1. Select base rate using nested season and room type check.<br>2. `Gross = Base_Rate * Nights_Stayed`.<br>3. `Discount = 15%` of Gross if `Nights_Stayed > 7`; else `0`.<br>4. `Guest_Price = Gross - Discount`.<br>5. `Total_Revenue = ∑ Guest_Price`. | • Individual Guest Final Price<br>• Total Hotel Revenue | • Loop processes `N` guests.<br>• **Peak Rates**: Standard = 5000, Deluxe = 8000, Suite = 12000.<br>• **Off-Peak Rates**: Standard = 3000, Deluxe = 5000, Suite = 8000.<br>• 15% discount strictly applies when `Nights_Stayed > 7`. |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Integer)<br>• `Season` (String)<br>• `Room_Type` (String)<br>• `Nights_Stayed` (Integer) | 1. Initialize `Total_Hotel_Revenue = 0`.<br>2. **Loop `i` from 1 to `N`**:<br>&nbsp;&nbsp;&nbsp;&nbsp;a. Read `Season`, `Room_Type`, `Nights_Stayed`.<br>&nbsp;&nbsp;&nbsp;&nbsp;b. Determine `Base_Rate`.<br>&nbsp;&nbsp;&nbsp;&nbsp;c. Compute `Gross = Base_Rate * Nights_Stayed`.<br>&nbsp;&nbsp;&nbsp;&nbsp;d. If `Nights_Stayed > 7`, `Discount = 0.15 * Gross`; else `0`.<br>&nbsp;&nbsp;&nbsp;&nbsp;e. `Guest_Price = Gross - Discount`.<br>&nbsp;&nbsp;&nbsp;&nbsp;f. `Total_Hotel_Revenue += Guest_Price`.<br>3. Display `Total_Hotel_Revenue` after loop. | • `Guest_Final_Price` (per guest)<br>• `Total_Hotel_Revenue` (final total) |


