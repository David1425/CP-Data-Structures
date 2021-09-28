#!/bin/bash

# Run this to stress test A.cpp and compare it with B.cpp
# Put in number of tests and folder in command line arguments

# example:
# test.sh 10 /usr/code
# stress test A.cpp 10 times in path /usr/code

echo "compiling scripts..."
g++ "${2}/gen.cpp" -o gen
g++ "${2}/A.cpp" -o A           # Put your program in A.cpp
g++ "${2}/B.cpp" -o B           # Put brute force program in B.cpp
g++ "${2}/checker.cpp" -o checker
echo "running..."

for i in $(seq 1 $1)
do
    # generate random data
    ./gen > "gen.in"
    
    # generate results
    ./A < "gen.in" > "A.out"
    ./B < "gen.in" > "B.out"
    
    # check difference
    ./checker < "gen.in" "A.out" "B.out"
done
echo "done"
