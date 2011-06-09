#include <iostream>
using namespace std;

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

  int num;
  if (!convert<int>(argv[1], &num)) {
    usage(argv);
    return -1;    
  }

  cout << num << " " <<  (isSquareFreeI(num) ? "is" : "is not")
       <<" square-free.";
  return 0;
}
