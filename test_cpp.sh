#!/bin/bash

if ls | grep 'exp_out.txt'; then 
	g++ -Wall $1 -o a.o && ./a.o < 'in.txt' > 'out.txt' 
	vimdiff 'exp_out.txt' 'out.txt' 
else
	g++ -Wall $1 -o a.o && ./a.o < 'in.txt' 
fi

