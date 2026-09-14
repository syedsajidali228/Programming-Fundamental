Question 04: Online Shopping Bill Calculator


1. Algorithm
   
Step 1: Start.

Step 2: Read quantity(q), price_per_item(p), discount_percent (d), and tax_percent (t).

Step 3: Validate input values:

        If (q <= 0 OR p <= 0 OR d < 0 OR d > 100 OR t < 0):
            Print 'Error: Invalid input parameters.'
            Go to Step 8 (terminate execution).
            
Step 4: Compute Stage 1 - Subtotal: s = q * p.

Step 5: Compute Stage 2 Discounted Amount: a = s - (s * d) / 100.0.

Step 6: Compute Stage 3 - Final Bill: final_bill = a + (a * t) / 100.0.

Step 7: Display Itemized Bill Summary (Subtotal 's', Discounted Amount 'a', Tax Added, Final Payable 'final_bill').

Step 8: End.

3. Problem Analysis Chart (PAC)
   
Given Data / Inputs	Processing & Operations	Required Output	Constraints & Rules

• q (Quantity purchased)

• p (Price per item)

• d (Discount percentage)

• t (Tax percentage)	1. Input validation check.

2. Subtota: s = q × p.
  
4. Discounted Amount: a = s - (s × d)/100.

5. Final Bill: final_bill = a + (a × t)/100.	• Error message (if invalid)


• Subtotal (s)

• Discounted Amount (a)

• Final Payable Bill	• Inputs must be positive (q>0, p>0, d>=0, t>=0).

• Dependent staged functions.

• Single record transaction.

3. Input-Process-Output (IPO) Chart
   
Input	Processing	Output

• quantity (q: Integer)

• price (p: Float)

• discount_percent (d: Float)

• tax_percent (t: Float)	1. IF q <= 0 OR p <= 0 OR d < 0 OR d > 100 OR t < 0 THEN display error and terminate.

2. s = q * p
  
4. a = s - (s* d) / 100.0
   
6. final_bill = a + (a * t) / 100.0
   
8. Format and print bill receipt.	• Subtotal (s)
   
• Discounted Amount (a)

• Final Bill Amount

 
5. Pseudocode
   
begin

    read quantity, price_per_item, discount_percent, tax_percent
    
    if quantity <= 0 or price_per_item <= 0 or discount_percent < 0 or discount_percent > 100 or tax_percent < 0 then
        print "error: invalid input values. calculation terminated."
    else
        set subtotal = quantity * price_per_item
        set discounted_amount = subotal - (subtotal * discount_percent) / 100.0
        set final_bill = discounted_amount + (discounted_amount * tax_percent) / 100.0
        
        print "=== shopping bill receipt ==="
        print "subtotal: rs. ", subtotal
        print "discounted amount: rs. ", discounted_amount
        print "final payable bill: rs. ", final_bill
    end if
end

