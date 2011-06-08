#include <gmp.h>
#include <vector>
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

  mpz_t num;
  mpz_init(num);
  if (mpz_set_str(num, argv[1], 10) == -1) {
    mpz_clear(num);
    usage(argv);
    return -1;
  }

  vector<mpz_t*> facs;  
  pollardRhoFactor(num, facs);

  dump(num, "Prime factorization of", false);
  cout << " is [";
  vector<mpz_t*>::iterator it; 
  for (it = facs.begin(); it != facs.end(); it++) {
    dump(**it, "", false);

    if (it + 1 != facs.end()) {
      cout << ", ";
    }
    
    mpz_clear(**it);
    delete[] *it;
  }
  cout << "]" << endl;

  mpz_clear(num);
  return 0;
}
