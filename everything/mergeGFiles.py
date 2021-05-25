import glob
import os
import re


numbers = re.compile(r'(\d+)')
def numericalSort(value):
    parts = numbers.split(value)
    parts[1::2] = map(int, parts[1::2])
    return parts


def splitDistances(path, num_files):
    file = open(path + 'G.txt', 'r')
    data = file.read()
    if len(data) % num_files == 0:
        chunk_size = int(len(data) / num_files)
        for num_f in range(num_files):
            print('file ' + str(num_f) + ' out of ' + str(num_files))

            sub_file = open(path + '/split_G/G' + str(num_f) + '.txt', 'a')
            sub_file.write(data[num_f*chunk_size : (num_f + 1) * chunk_size])
            sub_file.close()
    else:
        print('the data size ' + str(len(data)) + ' is not divisable by ' + str(num_files))


def mergeDistances(path):
    file = open(path + 'G.txt', 'w')
    contents = []
    for filename in sorted(glob.glob(os.path.join(path + 'split_G/', '*.txt')), key=numericalSort):
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
    # path = 'C:/Users/Benedikt/Desktop/Uni/Bachelor/everything/git/Rec_Evaluation/everything/Data/Twitter/'
    # splitDistances(path, 199)
    mergeDistances(path)
    #path = 'C:/Users/Benedikt/Desktop/Uni/Bachelor/everything/git/everything/Data/Twitter/'
    #splitDistances(path, 500)
    #mergeDistances(path)
