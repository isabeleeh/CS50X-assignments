# TODO
from cs50 import get_string
import sys

# Argc to take in and check
if len(sys.argv) != 2:
    print("Usage: python readability.py Key")
    sys.exit()
if len(sys.argv[1]) != 26:
    print("Key must contain 26 characters.")
    sys.exit()

# Ask user to input a string as Plaintext
plaintext = get_string("plaintext: ")
ciphertext = []
key = sys.argv[1]

for i in range(len(plaintext)):
    if plaintext[i].isalpha():
        # handle letter
        index = ord(plaintext[i].lower()) - ord("a")
        if plaintext[i].islower():
            ciphertext.append(key[index].lower())
        else:
            ciphertext.append(key[index].upper())

    else:
        # Not letter
        ciphertext.append(plaintext[i])
print("ciphertext: " + "".join(ciphertext))
