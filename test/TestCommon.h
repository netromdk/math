#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <sstream>
#include <iostream>
using namespace std;

template <class T>
bool convert(char *str, T *var) {
  istringstream ss(str);
  return (ss >> *var);
}

#endif // TEST_COMMON_H
