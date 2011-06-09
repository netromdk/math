#include <vector>
#include <iostream>
using namespace std;

#include "Common.h"
#include "Eratosthenes.h"
using namespace Math;
using namespace Math::Sieve;

#include "TestCommon.h"

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <min> <max>" << endl
       << "Finds the primes in the range [min, max]." << endl;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    usage(argv);
    return -1;
  }

  mpz_t min;
  mpz_init(min);
  if (mpz_set_str(min, argv[1], 10) == -1) {
    mpz_clear(min);
    usage(argv);
    return -1;
  }

  mpz_t tmp;
  mpz_init(tmp);
  if (mpz_mod_ui(tmp, min, 2) != 0 || mpz_cmp_ui(min, 2) < 0) {
    mpz_clears(min, tmp, NULL);
    cout << "Min needs to be even and >= 2!" << endl;
    return -1;    
  }

  mpz_t max;
  mpz_init(max);
  if (mpz_set_str(max, argv[2], 10) == -1) {
    mpz_clears(min, max, tmp, NULL);
    usage(argv);
    return -1;
  }

  if (mpz_cmp(min, max) >= 0 || mpz_mod_ui(tmp, max, 2) != 0) {
    mpz_clears(min, max, tmp, NULL);    
    cout << "Max needs to be even and min < max!" << endl;
    return -1;    
  }

  vector<mpz_t*> primes = eratosthenesRange(max); //min, max);
  dump(max, "List of primes <=");
  vector<mpz_t*>::iterator it; 
  for (it = primes.begin(); it != primes.end(); it++) {
    dump(**it, "", false);

    if (it + 1 != primes.end()) {
      cout << ", ";
    }
    
    mpz_clear(**it);
    delete[] *it;
  }

  mpz_clears(min, max, tmp, NULL);
  

  /*



  vector<int> primes = eratosthenesRangeI(min, max);

  cout << "List of primes (" << primes.size()
       << ") in [" << min << ", " << max << "]:" << endl;
  for (vector<int>::iterator it = primes.begin();
       it != primes.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  */
  return 0;
}
