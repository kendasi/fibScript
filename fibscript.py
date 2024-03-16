import sys

def fibonacci(n):
  sequence = [0, 1]
  if n <= 0:
    print("ERROR: Parameter must be one positive integer.")
    return
  print("[", end="")
  l = 0
  while l < n:
    if l != 0:
      print(", ", end="")
    print(sequence[0], end="")
    sequence[0], sequence[1] = sequence[1], sequence[0] + sequence[1]
    l += 1
  print("]")

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
