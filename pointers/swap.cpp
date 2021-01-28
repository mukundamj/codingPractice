//Problem statement: Write a function to swap strings pointed by two pointers.
//The two pointers are const char * s1 = "Geeks" and const char * s2 = "ForGeeks"
#include <iostream>

using namespace std;

void swap(const char * & s1, const char * & s2) { //s1 and s2 should be made as reference otherwise s1 and s2 in the main function won't get swapped
  const char * t = s1;
  s1 = s2;
  s2 = t;
}

int main(int argc, const char * argv[]) {
  const char * s1 = "Geeks";
  const char * s2 = "For Geeks";
  printf("Before swap s1 = %s, s2 = %s\n", s1, s2);
  swap(s1, s2);
  printf("After swap s1 = %s, s2 = %s\n", s1, s2);
  return 0;
}

