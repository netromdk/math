#include <iostream>
using namespace std;

#include "Smooth.h"
#include "Common.h"
using namespace Math;
using namespace Math::Fac;

#include "TestCommon.h"

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <num> <B>" << endl
       << "Checks whether <num> is <B>-smooth." << endl;
}

int main(int argc, char **argv) {
  if (argc != 3) {
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

  mpz_t B;
  mpz_init(B);
  if (mpz_set_str(B, argv[2], 10) == -1) {
    mpz_clears(num, B, NULL);
    usage(argv);
    return -1;
  }

  mpz_t C;
  mpz_init(C);
  if (isSmooth(num, B, &C)) {
    dump(num, "", false);
    dump(B, " is", false);
    cout << "-smooth." << endl;
  }
  else {
    dump(num, "No.", false);
    dump(C, " is", false);
    cout << "-smooth." << endl;
  }  

  mpz_clears(num, B, C, NULL);  
  return 0;
}
