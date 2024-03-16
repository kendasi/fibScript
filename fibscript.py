import sys

def fibonacci(n):
    sequence = [0, 1]
    if n <= 0:
        print("ERROR: Parameter must be one positive integer.")
        return
    elif n == 1:
        print(f"[{sequence[0]}]")
        return
    elif n == 2:
        print(sequence)
        return
    else:
        while len(sequence) < n:
            next_num = sequence[-1] + sequence[-2]
            sequence.append(next_num)
        print(sequence)

def fib(n):
  try:
    fibonacci(n)
  except:
    print("ERROR: Parameter must be one positive integer.")

if __name__ == "__main__":
    parameter = sys.argv[1]
    # Read the file
    f = open(parameter, "r")
    code = f.read()
    f.close()
    # Split it into lines
    allLines = code.split("\n")
    # For each line of code
    for line in allLines:
      # Check that it's valid
      if ("fib(" in line):
        exec(line)
      else:
        print("ERROR: Unknown command. The only command is fib().")
