from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

cents = round(dollars * 100);

coins = 0
change_owed = cents
while change_owed >= 25:
    coins = coins + 1
    change_owed = change_owed - 25

while change_owed >= 10:
    coins = coins + 1
    change_owed = change_owed - 10

while change_owed >= 5:
    coins = coins + 1
    change_owed = change_owed - 5

while change_owed >= 1:
    coins = coins + 1
    change_owed = change_owed - 1

print(coins)
