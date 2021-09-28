#!/bin/bash

# Put in number of tests and folder in command line arguments

echo "compiling scripts..."
g++ "${2}/gen.cpp" -o gen
g++ "${2}/A.cpp" -o A
g++ "${2}/B.cpp" -o B
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
