import sys

w = open("status.txt", 'w+')
filename = sys.argv[1]
source = open(filename, 'r').read() + '\n'

try:
    compile(source, filename, 'exec')
    w.write("Success")
except SyntaxError:
    w.write("Fail")
