import random

def frequencyTable(dnaList):
    n = max([len(dna) for dna in  dnaList])
    frequency_matrix = {
        'A': [0]*n,
        'C': [0]*n,
        'G': [0]*n,
        'T': [0]*n
        }
    for dna in dnaList:
        for index, base in enumerate(dna):
            frequency_matrix[base][index] += 1
    return frequency_matrix


base = ['A','C','G','T']
dnaList = []

for i in range(1000):
    temp = random.choice(base)
    dnaList.append(temp)

matrix = frequencyTable(dnaList)
print(matrix)


for i in range(100):
    pos = random.randint(0,999)
    dnaList[pos] = random.choice(base)

mutatedMatrix = frequencyTable(dnaList)
print(mutatedMatrix)
