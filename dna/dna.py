import csv
import sys


def main():

    # Get imput text from user - database and sequence - Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.scv sequence.txt")

# Open the csv and the txt file and read its contents into memory
    filename = sys.argv[1]
    database = open(filename)
    data = csv.DictReader(database)

    filename = sys.argv[2]
    with open(filename) as f:
        sequence = f.read()

# Compute the longest run of consecutive repeats of the STR in the DNA sequence
    counts = {}
    for subseq_str in data.fieldnames[1:]:
        counts[subseq_str] = longest_match(sequence, subseq_str)


# Compare the STR counts against each row in the CSV file
# Print
    for row in data:
        if all(counts[subseq_str] == int(row[subseq_str]) for subseq_str in counts):
            print(row["name"])
            database.close()
            return

    print("no match")
    database.close()


def longest_match(sequence, subseq_str):
    longest = 0
    length = len(subseq_str)
    for i in range(len(sequence)):
        count = 0
        while True:
            start = i + length * count
            end = start + length
            if sequence[start:end] == subseq_str:
                count += 1
            else:
                break
        longest = max(longest, count)
    return longest


if __name__ == "__main__":
    main
