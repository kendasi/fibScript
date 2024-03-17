#include "bigint.h"
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>

using std::cerr;
using std::cout;

void printnl() { putchar('\n'); }
void printcoma() {
  putchar(',');
  putchar(' ');
}

void printn(const bigint &n) { cout << n; }

void printseq(const std::vector<bigint> &seq,
              size_t limit = std::string::npos) {
  putchar('[');

  size_t printed = 0;
  auto i = seq.begin();

  while (i != seq.end()) {
    printn(*i);

    i++;
    printed++;

    if (i == seq.end() || printed == limit) {
      putchar(']');
      break;
    }

    printcoma();
  }

  printnl();
}

const std::vector<bigint> initial_seq = {0, 1};
std::vector<bigint> cache_seq = initial_seq;
size_t cache_siz = 2;

void fib(uint64_t n) {
  if (n == 0) {
    cerr << "ERROR: Parameter must be one positive integer.\n";
    return;
  }

  std::vector<bigint> seq = cache_seq;

  if (n == 1) {
    printn(0);
    printnl();
    return;
  }

  if (n == 2) {
    printseq(initial_seq);
    return;
  }

  size_t seqsiz = seq.size();

  if (seqsiz < n) {
    seq.reserve(n);
    cache_seq.reserve(n);
  }

  while (seqsiz < n) {
    auto ei = seq.end();

    bigint next(*(ei - 1) + *(ei - 2));

    seq.emplace_back(next);
    seqsiz++;

    if (cache_siz < seqsiz) {
      cache_seq.emplace_back(next);
      cache_siz++;
    }
  }

  printseq(seq, n);
}

std::string trim_space(const std::string &str) {
  size_t stidx = 0;

  for (char c : str) {
    if (!std::isspace(c)) {
      break;
    }

    stidx++;
  }

  size_t endidx = str.length() - 1;

  for (auto i = str.rbegin(); i != str.rend(); i++) {
    if (!std::isspace(*i)) {
      break;
    }

    endidx--;
    if (stidx > endidx || endidx == 0)
      break;
  }

  if (stidx > endidx)
    return "";

  return str.substr(stidx, endidx - stidx + 1);
}

void usage(const char *bin) {
  cerr << "Usage: " << bin << " path/to/inputfile.fs\n";
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    usage(argv[0]);
    return -1;
  }

  std::ifstream infile;
  infile.open(argv[1]);

  if (!infile) {
    cerr << "ERROR: Failed opening input file\n";
    return -1;
  }

  std::string line;
  while (std::getline(infile, line)) {
    line = trim_space(line);

    if (line.empty()) {
      continue;
    }

    size_t endidx = line.find(")");

    if (line.find("fib(") != 0 || endidx == line.npos) {
      cerr << "ERROR: Unknown command '" << line
           << "'. The only command is fib().\n";

      continue;
    }

    size_t stidx = line.find("(") + 1;

    std::string digits = line.substr(stidx, endidx - stidx);

    if (digits.empty()) {
      putchar('\n');
      continue;
    }

    fib(std::stoul(digits));
  }

  return 0;
}
