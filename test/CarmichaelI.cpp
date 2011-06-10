#include <iostream>
using namespace std;

#include "Carmichael.h"
using namespace Math::Fac;

#include "TestCommon.h"

void usage(char **argv) {
  cout << "Usage: " << argv[0] << " <num>" << endl
       << "Checks whether <num> is a Carmichael number." << endl;
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

  if (isCarmichaelI(num)) {
    cout << num << " is a Carmichael number." << endl;
  }
  else {
    cout << "No, " << num << " is not a Carmichael number." << endl;    
  }

  return 0;
}
