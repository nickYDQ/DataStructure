// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Implementation and test driver for UNION/FIND implemented with a
// parent-pointer tree. This version does not use path compression.

#include <iostream>
using namespace std;
#define ROOT -1

// Parent-pointer tree implementation (without path compression)
#include "ufs.h"

// Driver to test the implementation, mainly its syntax
int main(int argc, char** argv) {
  ParPtrTree* gt = new ParPtrTree(16);
  cout << "start:" << endl;
  gt->print();

  cout << endl << "(0£¬2)" << endl;
  gt->UNION(0, 2);
  gt->print();

  cout <<endl<< "(1£¬2)" << endl;
  gt->UNION(1, 2);
  gt->print();
  return 0;
}
