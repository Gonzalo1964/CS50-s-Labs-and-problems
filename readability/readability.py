from cs50 import get_string

# Get input text from user
text = get_string("Text: ")

# Count number of letters
letters = 0
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

# Count number of words
words = len(text.split())

# Count number of sentences
sentences = 0
for i in range(len(text)):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1

# Calculate index
subindex = 0.0588 * 100 * letters / words - 0.296 * 100 * sentences / words - 15.8
float(subindex)
index = round(subindex)


# Print grade
if index < 1:
    print("Before Grade 1")
elif index > 1 and index < 16:
    print(f"Grade: {index}")
else:
    print("Grade 16+")