from sys import stdin 
""" 
Task:

The provided code stub reads two integers, a and b, from STDIN.

Add logic to print two lines. The first line should contain the result of integer division,

a//b. The second line should contain the result of float division, a/b.

No rounding or formmatting is necessary
"""


def main():
    a = int(stdin.readline().strip())
    b = int(stdin.readline().strip())

    integer_division = a // b 
    division = a / b 

    print(integer_division)
    print(division)


if __name__ == '__main__':
    main()