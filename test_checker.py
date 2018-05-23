import sys
import subprocess

source_f, input_f, output_f = sys.argv[1:]

with open(output_f, 'w') as ouf:
    with open(input_f, 'r') as inf:
        proc = subprocess.Popen("python " + source_f, stdout = ouf, stdin = inf)
        proc.wait()