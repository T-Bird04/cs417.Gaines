import string

wordFrequency = 0
targetWords = ["Rights", "rights", "Right", "right"]
wordInput = []
wordRefined = []
file = open('declaration.txt', 'r')
for word in file:
    wordInput.append(word)

for sentence in wordInput:
    sentence = sentence.translate(str.maketrans('', '', string.punctuation))
    #Punctuation removal from: https://stackoverflow.com/questions/265960/best-way-to-strip-punctuation-from-a-string
    wordRefined.append(sentence.split())

for targetWords in wordRefined:
    wordFrequency = wordFrequency + 1

print("The words 'Right' and 'Rights' appear ", wordFrequency, " times in the Declaration of Independace.")
