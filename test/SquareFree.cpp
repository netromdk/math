#include <gmp.h>
#include <iostream>
using namespace std;

#include "Common.h"
#include "SquareFree.h"
using namespace Math;

#include "TestCommon.h"

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <num>" << endl
       << "Checks whether <num> is square-free." << endl;
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

  dump(num, "", false);
  cout << " " <<  (isSquareFree(num) ? "is" : "is not")
       <<" square-free.";
  mpz_clear(num);
  return 0;
}
