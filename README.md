
# Harvard CS50: Introduction to Computer Science (Problem Sets)

This repository is dedicated to my solutions of the weekly problem sets in the course.
- Problem Sets 1 to 5 require the **C-programming language** to be used
- Problem Set 6 requires **Python**
- Problem Set 7 requires **Python** and **SQL**
- Problem Set 8 (Web Track) requires **Flask**, **HTML**, **CSS** and **Javascript**

## Problem Set 1
### Credit
[Link to full description](https://cs50.harvard.edu/x/2020/psets/1/credit/)
##### Context
A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

## Problem Set 2
### Readability
[Link to full description](https://cs50.harvard.edu/x/2020/psets/2/readability/)
##### Context
Implement a program that computes the approximate grade level needed to comprehend some text, per the below.
```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

### Substitution
[Link to full description](https://cs50.harvard.edu/x/2020/psets/2/substitution/)
##### Context
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

## Problem Set 3
### Plurality
[Link to full description](https://cs50.harvard.edu/x/2020/psets/3/plurality/)
##### Context
Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

### Runoff
[Link to full description](https://cs50.harvard.edu/x/2020/psets/3/runoff/)
##### Context
Implement a program that runs a runoff election, per the below.
```
./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

### Tideman
[Link to full description](https://cs50.harvard.edu/x/2020/psets/3/tideman/)
##### Context
Implement a program that runs a Tideman election, per the below.
```
./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```

## Problem Set 4
### Filter
[Link to full description](https://cs50.harvard.edu/x/2020/psets/4/filter/more/)
##### Context
Implement a program that applies filters to BMPs, per the below.
```
$ ./filter -r image.bmp reflected.bmp
```

### Recover
[Link to full description](https://cs50.harvard.edu/x/2020/psets/4/recover/)
##### Context
Implement a program that recovers JPEGs from a forensic image, per the below.
```
$ ./recover card.raw
```

## Problem Set 5
### Speller
[Link to full description](https://cs50.harvard.edu/x/2020/psets/5/speller/)
##### Context
Implement a program that spell-checks a file, a la the below, using a hash table.
```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```

## Problem Set 6
### Credit
[Link to full description](https://cs50.harvard.edu/x/2020/psets/6/credit/)
##### Context
Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
```
$ python credit.py
Number: 378282246310005
AMEX
```

### Readability
[Link to full description](https://cs50.harvard.edu/x/2020/psets/6/readability/)
##### Context
Implement a program that computes the approximate grade level needed to comprehend some text, per the below.
```
$ python readability.py
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

### DNA
[Link to full description](https://cs50.harvard.edu/x/2020/psets/6/dna/)
##### Context
Implement a program that identifies a person based on their DNA, per the below.
```
$ python dna.py databases/large.csv sequences/5.txt
Lavender
```

## Problem Set 7
### Movies
[Link to full description](https://cs50.harvard.edu/x/2020/psets/7/movies/)
##### Context
Write SQL queries to answer questions about a database of movies.

### Houses
[Link to full description](https://cs50.harvard.edu/x/2020/psets/7/houses/)
##### Context
Implement a program to import student data into a database, and then produce class rosters.
```
$ python import.py characters.csv
$ python roster.py Gryffindor

Lavender Brown, born 1979
Colin Creevey, born 1981
Seamus Finnigan, born 1979
Hermione Jean Granger, born 1979
Neville Longbottom, born 1980
Parvati Patil, born 1979
Harry James Potter, born 1980
Dean Thomas, born 1980
Romilda Vane, born 1981
Ginevra Molly Weasley, born 1981
Ronald Bilius Weasley, born 1980
```

## Problem Set 8
### Homepage
[Link to full description](https://cs50.harvard.edu/x/2020/tracks/web/homepage/)
##### Context
The internet has enabled incredible things: we can use a search engine to research anything imaginable, communicate with friends and family members around the globe, play games, take courses, and so much more. But it turns out that nearly all pages we may visit are built on three core languages, each of which serves a slightly different purpose:

HTML, or HyperText Markup Language, which is used to describe the content of websites;
CSS, Cascading Style Sheets, which is used to describe the aesthetics of websites; and
JavaScript, which is used to make websites interactive and dynamic.
Create a simple homepage that introduces yourself, your favorite hobby or extracurricular, or anything else of interest to you.

### Finance
[Link to full description](https://cs50.harvard.edu/x/2020/tracks/web/finance/)
##### Context
This is a part of the Harvard CS50 Introduction to Computer Science - Web Track.
We had to develop a web app via which you can manage portfolios of stocks. Not only will this tool allow you to check real stocks’ actual prices and portfolios’ values, it will also let you buy (okay, “buy”) and sell (okay, “sell”) stocks by querying IEX API for stocks’ prices sent as JSON.
