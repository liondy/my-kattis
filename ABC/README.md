## ABC
You will be given three integers A, B and C. The numbers will not be given in that exact order, but we do know that A is less than B and B less than C. In order to make for a more pleasant viewing, we want to rearrange them in a given order.

### Input
The first line contains the three positive integers A, B and C, not necessarily in that order. The three numbers will be less than or equal to 100.

The second line contains three uppercase letters ’A’, ’B’ and ’C’ (with no spaces between them) representing the desired order.

### Output
Output A, B and C in the desired order on a single line, separated by single spaces.

```
Sample Input 1	
1 5 3
ABC

Sample Output 1
1 3 5

Sample Input 2
6 4 2
CAB

Sample Output 2
6 2 4
```

## Solution
Consists of 2 methods:
### Main Method
- Get input with string
- Split the string input by " "
- Numbers are <= 100, so some numbers will consist of 2-3 character, so to get all characters to numbers:
```
number = (number * 10) + character
```
- If found space, then check the vector numbers first
- If the current maximal is lower than current, push the number, update the maximal
- Else, sort the numbers first
- Lastly, don't forget that the last numbers will not be check in the loop, therefore, outside loop should insert the number again
- Get sorter input
- Check this:
```
A = 0 --> print numbers index 0
B = 1 --> print numbers index 1
C = 2 --> print numbers index 2
```

### Sort Method
Have a O(n) complexity:
- Loop through the vector numbers from the last index
- If the current index is lower than index before, move the before index to current index
- Else overrite the current index with the numbers that want to be insert