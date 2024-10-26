# TODO: print Mario bricks using python
from cs50 import get_int

# Get input: int between 1-8
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Loop to print # with the given number
for i in range(1, height+1):
    # To print blanks for each first half
    for j in range(1, height-i+1):
        print(" ", end="")

    # To print # for each first half
    for j in range(1, i+1):
        print("#", end="")

    print("  ", end="")

    # To print # for each second half
    for j in range(1, i+1):
        print("#", end="")
    print()
