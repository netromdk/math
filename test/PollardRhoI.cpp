#include <iostream>
using namespace std;

#include "PollardRho.h"
using namespace Math::Fac;

#include "TestCommon.h"

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <num>" << endl
       << "Find a nontrivial prime factor of <num>." << endl;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    usage(argv);
    return -1;
  }

  int num;
  if (!convert<int>(argv[1], &num)) {
    usage(argv);
    return -1;    
  }

  int g = pollardRhoI(num);
  cout << "A factor of " << num << " is " << g << endl;
  return 0;
}
