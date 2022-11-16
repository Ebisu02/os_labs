printf 'Name\t\tSum\tTime\n'
g++ threads.cpp -o thread
g++ singlethread.cpp -o sthread
g++ pthread.cpp -o pthread

./thread
./sthread
./pthread

rm pthread
rm sthread
rm thread
