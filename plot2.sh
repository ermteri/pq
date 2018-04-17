#!/bin/bash
#plot 
cd plot
rm -rf 2
rm -rf 4
rm -rf 6
rm -rf 8
rm -rf 10
rm -rf 12
rm -rf 14
rm -rf 16
rm -rf 18
mkdir 2
mkdir 4
mkdir 6
mkdir 8
mkdir 10
mkdir 12
mkdir 14
mkdir 16
mkdir 18
cd ..
./run1.sh 10000 1000000 100 > plot/2/heap2.dat	
./run1.sh 10000 1000000 100 > plot/4/heap2.dat	
./run1.sh 10000 1000000 100 > plot/6/heap2.dat
echo "1 done \n"	
./run1.sh 9000 1000000 140 > plot/8/heap2.dat	
./run1.sh 9000 1000000 140 > plot/10/heap2.dat	
./run1.sh 9000 1000000 140 > plot/12/heap2.dat
echo "2 done \n"
./run1.sh 11000 1000000 60 > plot/14/heap2.dat	
./run1.sh 11000 1000000 60 > plot/16/heap2.dat	
./run1.sh 11000 1000000 60 > plot/18/heap2.dat	
echo "3 done \n"
cd plot
gnuplot heap.p
echo "plot done!"
display heap.png
echo "open graph"
