#!/bin/bash
#plot 
echo "This script will run a complexity comparision for two different piority queue implementaion linkedlist vs skewheap"	
echo "preperation......"	

rm -rf plot/1
rm -rf plot/2
rm -rf plot/3
rm -rf plot/4
rm -rf plot/5
rm -rf plot/6
rm -rf plot/7
rm -rf plot/8
rm -rf plot/9
mkdir plot/1
mkdir plot/2
mkdir plot/3
mkdir plot/4
mkdir plot/5
mkdir plot/6
mkdir plot/7
mkdir plot/8
mkdir plot/9

echo "compliling all component"
make
echo "SUCESSFUL COMPILED"
echo "simulation start"	
./run_list.sh $1 $2 0 > plot/1/linkedlist.dat
echo "1st run"	
./run_list.sh $1 $2 0 > plot/2/linkedlist.dat	
echo "2nd run"
./run_list.sh $1 $2 0 > plot/3/linkedlist.dat
echo "3rd run"
echo "linked list done"	
./run_heap.sh $1 $2 0 > plot/1/heap.dat	
echo "1st run"
./run_heap.sh $1 $2 0 > plot/2/heap.dat	
echo "2nd run"
./run_heap.sh $1 $2 0 > plot/3/heap.dat
echo "3rd run"
echo "skew heap done"	
echo "1st data pattern done"	
./run_heap.sh $1 $2 0 > plot/4/heap.dat	
echo "1st run"
./run_heap.sh $1 $2 0 > plot/5/heap.dat
echo "2nd run"	
./run_heap.sh $1 $2 0 > plot/6/heap.dat
echo "3rd run"
echo "skew heap done"	
./run_list.sh $1 $2 0 > plot/4/linkedlist.dat
echo "1st run"	
./run_list.sh $1 $2 0 > plot/5/linkedlist.dat
echo "2nd run"	
./run_list.sh $1 $2 0 > plot/6/linkedlist.dat
echo "3rd run"
echo "linkedlist done"	
echo "2nd data pattern done"
./run_list.sh $1 $2 0 > plot/7/linkedlist.dat
echo "1st run"	
./run_list.sh $1 $2 0 > plot/8/linkedlist.dat
echo "2nd run"	
./run_list.sh $1 $2 0 > plot/9/linkedlist.dat
echo "3rd run"
echo "linked list done"
./run_heap.sh $1 $2 0 > plot/7/heap.dat
echo "1st run"	
./run_heap.sh $1 $2 0 > plot/8/heap.dat
echo "2nd run"	
./run_heap.sh $1 $2 0 > plot/9/heap.dat
echo "3rd run"
echo "skew heap done"			
echo "3rd data pattern done"
echo "SIMULATION SUECCESSED,PLOTING GRAPH......"
rm heap.png
gnuplot plot/heap.p
gnuplot plot/heap_logscale.p
gnuplot plot/heap_derivative.p
echo "plot done!"
echo "open graph"
display heap.png
display heap_logscale.png
display heap_derivative.png
echo "not crashed!"

