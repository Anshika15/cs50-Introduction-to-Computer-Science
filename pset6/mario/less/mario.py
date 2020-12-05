from cs50 import get_int

while True:
    num = get_int("Height: ")
    if num >= 1 and num <= 8:
        break

for i in range(num):
    for j in range(num - i - 1):
        print(" ", end = "")
    for k in range(num - i - 1, num):
        print("#", end = "");
    print()


