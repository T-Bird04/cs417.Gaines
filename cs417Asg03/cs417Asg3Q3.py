def charCount(userInput):
    temp = userInput.replace(" ", "")
    chars = len(temp)
    return chars


def Main():
    userInput = input("Please enter input:")
    charTotal = charCount(userInput)
    print("Characters Total: ",charTotal)


Main()
