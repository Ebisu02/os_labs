#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> s;
long int sum = 0;

int main() {
  int size = 1000;
  for (int i = 0; i < size; ++i) {
    s.push_back(i + 1);
  }
  auto r_tnow = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < size; ++i) {
    sum += s[i]; 
  }
  auto r_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now() - r_tnow);
  cout << "SingleThread\t" << sum << "\t" << (double)r_time.count() * 1e-9 << "\n";
}
