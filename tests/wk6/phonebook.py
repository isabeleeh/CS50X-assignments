import csv
from cs50 import get_string

name = get_string("what's your name: ")
number = get_string("what's your number: ")

# Open CSV file
with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])