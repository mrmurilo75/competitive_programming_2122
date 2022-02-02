#!/bin/bash

touch 'in.txt' 'exp_out.txt'
g++ -O2 -std=gnu++11 generator.cpp -o a.o && ./a.o 1> 'in.txt' 2> 'exp_out.txt'

