#!/bin/bash
#plot


cd plot
gnuplot heap.p >stat.txt
display heap.png
