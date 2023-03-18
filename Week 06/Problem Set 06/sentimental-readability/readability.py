from cs50 import get_string
s = get_string("Text: ")

L, S = 0, 0
for c in s:
    if c.isalpha():
        L += 1
    if c == "." or c == "!" or c == "?":
        S += 1

G = round(0.0588 * 100 * L / len(s.split()) - 0.296 * 100 * S / len(s.split()) - 15.8)
if G < 1:
    print("Before Grade 1")
elif G >= 16:
    print("Grade 16+")
else:
    print(f"Grade {G}")