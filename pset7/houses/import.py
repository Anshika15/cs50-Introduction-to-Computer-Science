# TODO
from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)
    
db = SQL("sqlite:///students.db")

filename = argv[1];

with open (filename, "r") as characters:
    reader = csv.DictReader(characters)
    
    for row in reader:
        l = []
        
        for subname in row["name"].split(" "):
            l.append(subname)
        l.append(row["house"])
        l.append(row["birth"])
        
        if len(l) == 5:
            db.execute("INSERT INTO students (first, middle, last, house, birth) values(?, ?, ?, ?, ?)", l[:5])
            
        if len(l) == 4:
            db.execute("INSERT INTO students (first, last, house, birth) values(?, ?, ?, ?)", l[:4])
        
    
    
    
    
#print(filename)


