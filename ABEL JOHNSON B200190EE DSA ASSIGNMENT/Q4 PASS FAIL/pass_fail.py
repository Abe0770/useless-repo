import sys

try:
    f = open("marks.txt", "r")
except FileNotFoundError:
    print("Error : File not found!")
    sys.exit()

line = ""
string = ""
arr = [0, 0, 0, 0]
grade = ['F', 'E', 'D', 'C', 'B', 'A']

print("\033[1mRESULT")
print("NAME\t\t       PHYSICS\t    MATHS     CHEMISTRY    BIOLOG     TOTAL\tFINAL GRADE")
print("\033[0m")

for line in f:
    sum = 0
    mark = 0
    line = line.strip()
    words = line.split()
    string = words[0]
    arr[0] = int(words[1])
    arr[1] = int(words[2])
    arr[2] = int(words[3])
    arr[3] = int(words[4])
    print("{:<16}".format(string), end='')

    for i in range(4):
        mark = 0 if arr[i] < 40 else (5 if arr[i] > 80 else (arr[i]//10)-3)
        if grade[mark] == 'F':
            print("\033[0;31m", end='')
        elif grade[mark] == 'A':
            print("\033[0;32m", end='')
        print("{:10d}-{}".format(arr[i], grade[mark]), end='')
        print("\033[0m", end='')
        sum = sum + arr[i]
    
    print("{:10d}\t".format(sum), end='')
    sum = 0 if sum < 160 else (5 if sum > 320 else (sum//40)-3)
    if grade[sum] == 'F':
        print("\033[0;31m", end='')
    elif grade[sum] == 'A':
        print("\033[0;32m", end='')
    print("{:>6}".format(grade[sum]))
    print("\033[0m")

f.close()

