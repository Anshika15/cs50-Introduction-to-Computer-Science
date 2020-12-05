# TODO
from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)
    
houses = argv[1]

db = SQL("sqlite:///students.db")
sql = "SELECT * FROM students WHERE house = %s ORDER BY last, first"

for row in db.execute(sql, houses):
    if not row["middle"]:
        print("{} {}, born {}".format(row["first"], row["last"], row["birth"]))
    else:
        print("{} {} {}, born {}".format(row["first"], row["middle"], row["last"], row["birth"]))

        