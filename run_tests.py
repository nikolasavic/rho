#!/usr/bin/python

import sys, subprocess, re

# Help
if "-h" in sys.argv or "--help" in sys.argv:
    print("Test Runner")
    print(" Options:")
    print("  --pass (-p)")
    print("  --fail (-f)")
    print("  --all (-a)")
    print()
    sys.exit(0)

# Find tests
test_list = []
regex = re.compile("^(test_\w+)")
with open("Makefile", "r") as file:
    for line in file:
        m = regex.match(line)
        if m:
            test_list.append(m.group(0))

# Parse args
print_pass = False
print_fail = False
if "--fail" in sys.argv or "-f" in sys.argv:
    print_fail = True
if "--pass" in sys.argv or "-p" in sys.argv:
    print_pass = True


# Run tests
exit_codes = []
pass_count = 0
fail_count = 0
error = None

for test in test_list:
    if "-a" in sys.argv or "-all" in sys.argv:
        run = subprocess.run(["make", test])
        print()
        next

    run = subprocess.run(["make", test], capture_output=True, text=True)
    lines = run.stdout.splitlines()

    for l in lines:
        if ":PASS" in l:
            pass_count += 1
            if print_pass:
                print(l)
        elif ":FAIL" in l:
            fail_count += 1
            if print_fail:
                print(l)
        elif run.returncode != 0:
            error = run.stderr

    exit_codes.append(run.returncode)

# Report
print()
print(f"Passing tests: {pass_count}")
print(f"Failing tests: {fail_count}")

if error:
    print()
    print("Error")
    print(error)

if sum(exit_codes) == 0:
    code = 0
else:
    code = 1

sys.exit(code)
