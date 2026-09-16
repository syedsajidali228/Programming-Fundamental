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


   
### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • `q` (Quantity purchased)<br>• `p` (Price per item)<br>• `d` (Discount percentage)<br>• `t` (Tax percentage) | 1. Input validation check.<br>2. Subtotal: `s = q * p`.<br>3. Discounted Amount: `a = s - (s * d) / 100`.<br>4. Final Bill: `final_bill = a + (a * t) / 100`. | • Error message (if invalid)<br>• Subtotal (`s`)<br>• Discounted Amount (`a`)<br>• Final Payable Bill | • Inputs must be positive (`q > 0`, `p > 0`, `d >= 0`, `t >= 0`).<br>• Dependent staged functions.<br>• Single-record transaction (no loop needed). |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `quantity` (`q`: Integer)<br>• `price` (`p`: Float)<br>• `discount_percent` (`d`: Float)<br>• `tax_percent` (`t`: Float) | 1. IF `q <= 0 OR p <= 0 OR d < 0 OR d > 100 OR t < 0` THEN display error and terminate.<br>2. `s = q * p`<br>3. `a = s - (s * d) / 100.0`<br>4. `final_bill = a + (a * t) / 100.0`<br>5. Display itemized receipt. | • Subtotal (`s`)<br>• Discounted Amount (`a`)<br>• Final Bill Amount |
