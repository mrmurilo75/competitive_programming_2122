#!/bin/bash

g++ -Wall $1 -o a.o && ./a.o < 'in.txt'

