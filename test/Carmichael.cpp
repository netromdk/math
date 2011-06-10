#include <iostream>
using namespace std;

#include "Common.h"
#include "Carmichael.h"
using namespace Math;
using namespace Math::Fac;

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <num>" << endl
       << "Checks whether <num> is a Carmichael number." << endl;
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

  if (isCarmichael(num)) {
    dump(num, "", false);
    cout << " is a Carmichael number." << endl;
  }
  else {
    dump(num, "No,", false);
    cout << " is not a Carmichael number." << endl;    
  }

  mpz_clear(num);
  return 0;
}
