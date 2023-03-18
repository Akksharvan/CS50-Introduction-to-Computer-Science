import csv
import sys

def main():
    if len(sys.argv) != 3:
        print("Incorrect number of arguments")
        return

    a, b = [], []
    with open(sys.argv[1], "r") as f:
        r = csv.DictReader(f)
        a = r.fieldnames[1:]
        for x in r:
            b.append(x)

    with open(sys.argv[2], "r") as f:
        s = f.readline()
        for x in b:
            for y in a:
                if longest_match(s, y) != int(x[y]):
                    break
                print(x["name"])
                return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)
    return longest_run

main()
