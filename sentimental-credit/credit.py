# TODO
from cs50 import get_int

# Get input of the number
number = get_int("Number: ")
len = len(str(number))

AE = (34, 37)
MC = (51, 52, 53, 54, 55)

# Get first part of sum
sum = 0
for i in range(len):
    if i % 2 == 0:
        odd = number % pow(10, i+1) // pow(10, i)
        sum += odd
    else:
        even = ((number // pow(10, i)) % 10) * 2
        sum += even // 10 + even % 10

# Check total sum
if sum % 10 == 0:
    firstone = number // pow(10, len-1)
    firsttwo = number // pow(10, len-2)
    if firstone == 4 and (len == 13 or len == 16):
        print("VISA")
    elif firsttwo in AE and len == 15:
        print("AMEX")
    elif firsttwo in MC and len == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")