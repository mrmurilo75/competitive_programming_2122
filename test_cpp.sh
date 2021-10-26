#!/bin/bash

g++ -Wall $1 -o a.o && ./a.o < 'in.txt' > 'out.txt' 
if ls | grep 'exp_out.txt'; then 
	vimdiff 'out.txt' 'exp_out.txt'
else
	cat 'out.txt'
fi

