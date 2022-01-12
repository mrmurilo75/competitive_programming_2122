#!/bin/bash

if ls | grep 'exp_out.txt'; then 
	g++ -Wall -O1 -std=gnu++14 $1 -o a.o && ./a.o < 'in.txt' > 'out.txt' 
	vimdiff 'exp_out.txt' 'out.txt' 
else
	g++ -Wall $1 -o a.o && ./a.o < 'in.txt' 
fi

