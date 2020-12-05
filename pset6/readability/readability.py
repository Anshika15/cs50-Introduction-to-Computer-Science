from cs50 import get_string
import math

s = get_string("Text: ")

letters = 0
words = 1
sen = 0
for i in range(len(s)):
    if s[i].isalpha():
        letters = letters + 1
    if s[i] == " " and s[i + 1]:
        words += 1
    if s[i] == '.' or s[i] == '?' or s[i] == '!':
        sen += 1


L = (float(letters) / float(words)) * 100
S = (float(sen) / float(words)) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

ind = round(index);
if ind < 1:
    print("Before Grade 1")
elif ind >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

