#include <gmp.h>
#include <sstream>
#include <iostream>
using namespace std;

#include "Common.h"
#include "PollardRho.h"
using namespace Math;
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

  mpz_t num, g;
  mpz_init(num);
  if (mpz_set_str(num, argv[1], 10) == -1) {
    mpz_clear(num);
    usage(argv);
    return -1;
  }
  
  mpz_init(g);
  pollardRho(num, g);
  dump(num, "A factor of", false);
  dump(g, " is");

  mpz_clears(num, g, NULL);
  return 0;
}
