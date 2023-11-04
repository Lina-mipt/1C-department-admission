import subprocess
import os

# are two answers equivalent?
def compare(name, ans1, ans2):
    with open('./' + name + '.in', 'r') as input:
        n, m = map(int, input.readline().split())
        w, h = map(int, input.readline().split())
        dist = [list(map(int, input.readline().split())) for i in range(n + 1)]
        k = int(input.readline())
        bad = set([tuple(map(int, input.readline().split())) for i in range(k)])
        f = int(input.readline())
        cheaters = [list(map(int, input.readline().split())) for i in range(f)]
        for i in range(f):
            WA = 'Wrong answer in query ' + str(i + 1)
            if (ans1[i] == -1 or ans2[i] == -1):
                if ans1 != ans2:
                    return WA
            else:
                if (ans1[i], cheaters[i][0]) in bad or (ans1[i], cheaters[i][1]) in bad:
                    return WA
                ans1[i] -= 1
                ans2[i] -= 1
                x1, y1 = ans1[i] // (m + 1), ans1[i] % (m + 1)
                x2, y2 = ans2[i] // (m + 1), ans2[i] % (m + 1)

                cheaters[i][0] -= 1
                cheaters[i][1] -= 1
                xc1, yc1 = cheaters[i][0] // (m + 1), cheaters[i][0] % (m + 1)
                xc2, yc2 = cheaters[i][1] // (m + 1), cheaters[i][1] % (m + 1)
                if (x1 - xc1) ** 2 + (x1 - xc2) ** 2 + (y1 - yc1) ** 2 + (y1 - yc2) ** 2 != \
                (x2 - xc1) ** 2 + (x2 - xc2) ** 2 + (y2 - yc1) ** 2 + (y2 - yc2) ** 2:
                    return WA
    return "Test " + name + " passed."


# run solution in test
def run_test(name):
    input = open('./' + name + '.in', 'r')
    process = subprocess.run('../bin/solution', stdin=input, stdout=subprocess.PIPE, encoding='utf-8')
    input.close()
    answer = open('./' + name + '.out', 'r')
    result = process.stdout
    my = process.stdout
    correct = answer.read()
    answer.close()
    my = [int(i) for i in my.strip('\n').split('\n')]
    correct = [int(i) for i in correct.strip('\n').split('\n')]
    print(compare(name, my, correct))


# run all tests
if __name__ == "__main__":
    for filename in os.listdir("./"):
        if filename.endswith(".in"):
            run_test(filename[:-3])

