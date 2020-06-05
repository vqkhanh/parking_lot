# Run UT Google Test

#### Install:

- sudo apt-get install libgtest-dev

- sudo apt-get install cmake

- cd /usr/src/gtest

 - sudo cmake CMakeLists.txt
 
- sudo make

#### Copy lib into /usr/lib :

- sudo cp *.a /usr/lib


#### Build and run UT:

- cd parking_lot/bin/functional_spec/build

- cmake ../

 - make
 
./run_functional_tests
