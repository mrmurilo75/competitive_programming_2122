#!/bin/bash

cat $1 | xclip -sel clip
if ls | grep 'exp_out.txt'; then 
	g++ -Wall -O2 -std=gnu++11 $1 -o a.o && ./a.o < 'in.txt' > 'out.txt' \
    && cat 'out.txt' \
	&& vimdiff 'exp_out.txt' 'out.txt' 
else
	g++ -Wall $1 -o a.o && ./a.o < 'in.txt' 
fi

