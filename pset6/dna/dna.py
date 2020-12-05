from sys import argv, exit
import csv

def get(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)

def match(reader, data):
    for line in reader:
        person = line[0]
        values = [ int(val) for val in line[1:] ]
        if values == data:
            print(person)
            return
    print("No match")


def main():
    if len(argv) != 3:
        print("missing command-line argument")
        exit(1)

    with open(argv[1], "r") as perosnData:
        reader = csv.reader(perosnData)
        sequences = next(reader)[1:]

        with open(argv[2]) as  file:
            s = file.read()
            data = [get(s, seq) for seq in sequences]

        match(reader, data)

if __name__ == "__main__":
    main()