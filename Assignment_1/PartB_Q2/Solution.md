Name: Syed Sajid Ali

Roll No: 26k-0013

Sections: BAI-1A


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

### 2. Problem Analysis Chart (PAC)

| Given Data / Inputs | Processing & Operations | Required Output | Constraints & Rules |
| :--- | :--- | :--- | :--- |
| • Initial floor = 0<br>• `N` (Total requests)<br>• `requested_floor` (for each request) | 1. Compare `requested_floor` with `current_floor` for each request.<br>2. `requested > current` → Print "Moving Up".<br>3. `requested < current` → Print "Moving Down".<br>4. `requested == current` → Print "Doors Opening".<br>5. Update `current_floor = requested_floor` after each stop. | • Direction message for each stop ("Moving Up", "Moving Down", "Doors Opening")<br>• Updated current floor status | • Elevator always starts at Floor 0.<br>• Process requests sequentially one by one in a loop.<br>• List of `N` floor requests. |

### 3. Input-Process-Output (IPO) Chart

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Integer, total requests)<br>• `requested_floor` (Integer sequence) | 1. Set `current_floor = 0`.<br>2. **Loop `i` from 1 to `N`**:<br>&nbsp;&nbsp;&nbsp;&nbsp;a. Read `requested_floor`.<br>&nbsp;&nbsp;&nbsp;&nbsp;b. IF `requested_floor > current_floor` → Output "Moving Up".<br>&nbsp;&nbsp;&nbsp;&nbsp;c. ELSE IF `requested_floor < current_floor` → Output "Moving Down".<br>&nbsp;&nbsp;&nbsp;&nbsp;d. ELSE → Output "Doors Opening".<br>&nbsp;&nbsp;&nbsp;&nbsp;e. Set `current_floor = requested_floor`. | • Direction status string per request ("Moving Up" / "Moving Down" / "Doors Opening") |


<img width="1052" height="1404" alt="Q2_PartB_PC" src="https://github.com/user-attachments/assets/46722792-7274-491f-936d-25b25f2ccaa6" />

<img width="6120" height="8160" alt="Q2_PartB_FC-1" src="https://github.com/user-attachments/assets/8326a01b-4df0-49a9-96c7-d85ca60dd013" />

<img width="6120" height="8160" alt="Q2_PartB_FC-2" src="https://github.com/user-attachments/assets/3bbbef2d-a399-4f97-b033-da964533e792" />
