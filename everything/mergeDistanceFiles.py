import glob
import os
import re


numbers = re.compile(r'(\d+)')
def numericalSort(value):
    parts = numbers.split(value)
    parts[1::2] = map(int, parts[1::2])
    return parts


def splitDistances(path, num_files):
    file = open(path + 'dAtoC.txt', 'r')
    lines = file.readlines()
    if len(lines) % num_files == 0:
        lines_per_file = int(len(lines) / num_files)
        for num_f in range(num_files):
            print('file ' + str(num_f) + ' out of ' + str(num_files))
            result = []
            for line in range(lines_per_file):
                index = num_f * lines_per_file + line
                print('line ' + str(index))
                result.append(lines[index])
            sub_file = open(path + '/split_dAtoC/dAtoC' + str(num_f) + '.txt', 'a')
            sub_file.write(''.join(result))
            sub_file.close()
    else:
        print('the number of lines ' + str(len(lines)) + ' is not divisable by ' + str(num_files))


def mergeDistances(path):
    file = open(path + 'dAtoC.txt', 'w')
    contents = []
    for filename in sorted(glob.glob(os.path.join(path + 'split_dAtoC/', '*.txt')), key=numericalSort):
        with open(filename, 'r') as f:
            print(filename)
            contents.append(f.read())
    file.write(''.join(contents))
    file.close()


def check_contents(path):
    #file = open(path + 'dAtoCtest.txt', 'r')
    file2 = open(path + 'dAtoC.txt', 'r')
    lines = file2.readlines()
    file2.close()
    print(len(lines))
    print(len(lines[0].split(',')))

    file = open(path + 'dFtoC.txt', 'r')
    lines1 = file.readlines()
    file.close()
    print(len(lines1))
    print(len(lines1[0].split(',')))
    #if file.read() == file2.read():
    #    print('Both files have the same content')
    same = True
    for i in range(len(lines1)):
        if lines[i] != lines1[i]:
            same = False
            break
    print(same)

if __name__ == '__main__':
    path = './Data/Twitter/'
    mergeDistances(path)
    #path = 'C:/Users/Benedikt/Desktop/Uni/Bachelor/everything/git/everything/Data/Twitter/'
    #splitDistances(path, 500)
    #mergeDistances(path)
