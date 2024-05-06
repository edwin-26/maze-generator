#!/bin/bash
g++ -c get_validate_inputs.cpp -std=c++11
g++ -c functions.cpp -std=c++11
g++ -c main.cpp -std=c++11
g++ get_validate_inputs.o functions.o main.o -o maze_generator -std=c++11 -lcgicc
