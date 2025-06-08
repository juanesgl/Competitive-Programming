from sys import stdin

""" 
Task:

The provided code stub reads two integers from STDIN, a and b. Add code to print three lines where:

1.The first line contains the sum of the two numbers.
2.The second line contains the difference of the two numbers (first - second).
3.The third line contains the product of the two numbers.

"""


def main():

    a = int(stdin.readline().strip())
    b = int(stdin.readline().strip())

    addition = a + b 
    difference = a - b

    multiplication = a * b

    print(addition)
    print(difference)
    print(multiplication)
      

if __name__ == '__main__':
    main()