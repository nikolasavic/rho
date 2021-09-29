#!/usr/bin/python

import sys, subprocess, re

# Find tests
test_list = []
regex = re.compile("^(test_\w+)")
with open("Makefile", "r") as file:
    for line in file:
        m = regex.match(line)
        if m:
            test_list.append(m.group(0))

# Run tests
exit_codes = []
for test in test_list:
    run = subprocess.run(["make", test])
    exit_codes.append(run.returncode)

# Exit code
if sum(exit_codes) == 0:
    print()
    print("All pass!")
    code = 0
else:
    print()
    print("Fail!")
    code = 1

sys.exit(code)
