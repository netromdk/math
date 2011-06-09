#include <iostream>
using namespace std;

#include "Smooth.h"
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

  int num;
  if (!convert<int>(argv[1], &num)) {
    usage(argv);
    return -1;    
  }

  int B;
  if (!convert<int>(argv[2], &B)) {
    usage(argv);
    return -1;    
  }

  int C;
  if (isSmooth(num, B, &C)) {
    cout << num << " is " << B << "-smooth." << endl;
  }
  else {
    cout << "No. " << num << " is " << C << "-smooth." << endl;    
  }

  return 0;
}
