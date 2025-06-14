from sys import stdin

"""
Task:

Given an integer, n, perform the following conditional actions:

- If n is odd, print Weird
- If n is even and in the inclusive range of 2 to 5, print Not Weird
- If n is even and in the inclusive range of 6 to 20, print Weird
- If n is even and greater than 20, print Not Weird 
"""

def main():

    n = int(stdin.readline().strip())

    if n % 2 == 0 and n >= 2 and n <= 5 :
        print("Not Weird")
    elif n % 2 == 0 and n >= 6 and n <= 20:
        print("Weird")

    elif n % 2 == 0 and n >= 20:
        print("Not Weird")

    else:
        print("Weird")
    
if __name__ == '__main__':
    main()