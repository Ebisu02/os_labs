#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> s;
long int sum = 0;

int main() {
  for (int i = 0; i < 1000; i++) {
    s.push_back(1);
  }
  auto r_tnow = std::chrono::high_resolution_clock::now();
  for (vector<int>::iterator it = s.begin(); it != s.end(); ++it) {
    sum += (*it); 
  }
  auto r_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now() - r_tnow);
  cout << (double)r_time.count() * 1e-9 << "\n";
}
