#include <iostream>

using namespace std;

int getSize() {
  // prompt
  cout << "Please input array size (1-10): ";
  int size;
  cin >> size;
  cout << endl;
  return size;
}

char* createAndGetElements(int size) {
  // prompt
  cout << "Please input array elements: ";
  char* out = new char[size + 1];
  for (int i = 0; i < size; i++) {
    // input each element
    cin >> out[i];
  }
  out[size] = '\0';
  cout << endl;
  return out;
}

void swap(char* c1, char* c2) {
  char c = *c1;
  *c1 = *c2;
  *c2 = c;
}

bool testAndSwapIfNecessary(char* c1, char* c2) {
  // if the two pointers are different
  if (c1 != c2) {
    // compare c1 and every pointer between c1 and c2 with c2
    for (char* cTemp = c1; cTemp < c2; cTemp++) {
      if (*cTemp == *c2) {
        // if any of them are the same as c2, no need to swap and reject the case
        return false;
      }
    }
    // if different and it passes the test, swap them, then return true
    swap(c1, c2);
  }
  // if the two pointers are the same, simply return true
  return true;
}

void showPermutation(char* elements, int size, int offset) {
  if (size == offset) {
    cout << elements << endl;
    return;
  }
  for (int i = offset; i < size; i++) {
    // swap if this case is new
    if (testAndSwapIfNecessary(elements + offset, elements + i)) {
      // recursive step
      showPermutation(elements, size, offset + 1);
      // swap it back
      swap(elements + offset, elements + i);
    }
  }
}

void calculateAndDisplayPermutation(char* elements, int size) {
  cout << "The permutation are:" << endl;
  showPermutation(elements, size, 0);
  cout << endl;
}

bool askIfContinue() {
  char contC;
  cout << "Continue to use this program? (C / c to continue): ";
  cin >> contC;
  return contC == 'c' || contC == 'C';
}

int main() {
  bool cont = true;

  while (cont) {

    // ask the user for number of elements
    int size = getSize();

    // get the elements from the user
    char* elements = createAndGetElements(size);

    // display all permutations of the elements
    calculateAndDisplayPermutation(elements, size);

    // delete the elements, freeing the memory
    delete[] elements;

    // ask if user want to continue the program
    cont = askIfContinue();
  }

  return 0;
}
