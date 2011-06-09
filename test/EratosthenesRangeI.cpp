#include <vector>
#include <iostream>
using namespace std;

#include "Eratosthenes.h"
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

  int min;
  if (!convert<int>(argv[1], &min)) {
    usage(argv);
    return -1;    
  }

  if ((min % 2 != 0) || min < 2) {
    cout << "Min needs to be even and >= 2!" << endl;
    return -1;
  }

  int max;
  if (!convert<int>(argv[2], &max)) {
    usage(argv);
    return -1;    
  }

  if (min >= max || (max % 2 != 0)) {
    cout << "Max needs to be even and min < max!" << endl;
    return -1;
  }  

  vector<int> primes = eratosthenesRangeI(min, max);

  cout << "List of primes (" << primes.size()
       << ") in [" << min << ", " << max << "]:" << endl;
  for (vector<int>::iterator it = primes.begin();
       it != primes.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;  
  return 0;
}
