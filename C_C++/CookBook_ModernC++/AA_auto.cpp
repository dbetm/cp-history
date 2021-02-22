// #include <iostream>
// #include <cstdlib>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
  // Auto: Automatic type deduction
  auto integer = 42; // int
  auto simple_str = "hey you"; // char const *
  auto vector1 = { 1, 2, 3}; // std::initializer_list<int>

  auto char_array = new char[10]{ 0 }; // char *
  auto vector2 = vector<int> { 1, 2, 3}; // vector<int>
  auto p = make_shared<int>(42); // shared_ptr<int>

  return 0;
}
