#include <thread>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

vector<int> s;
long int sum = 0;

void get_sum(vector<int> v, int st, int cap) {
  for (int i = st; i < cap; ++i) {
    sum += v[i];
  }
}

int main() {
  int size = 1000;
  for (int i = 0; i < size; ++i) {
    s.push_back(i + 1);
  }
  auto r_tnow = std::chrono::high_resolution_clock::now();
  thread t1(get_sum, s, 0, size / 4);
  thread t2(get_sum, s, size / 4, (2 * size) / 4);
  thread t3(get_sum, s, (2 * size) / 4, (3 * size) / 4);
  thread t4(get_sum, s, (3 * size) / 4, size);
  
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  auto r_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now() - r_tnow);
  cout << "Thread-lib\t" << sum << "\t" << (double)r_time.count() * 1e-9 << "\n";
}
