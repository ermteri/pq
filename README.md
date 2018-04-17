# Pioritory_Queue_ENGskill
![Build Status](https://travis-ci.org/GiantPanda0090/Pioritory_Queue_ENGskill.svg?branch=master)

TravisCI:https://travis-ci.org/GiantPanda0090/Pioritory_Queue_ENGskill/builds

SonarQube: https://sonarcloud.io/dashboard?id=Pioritory_Queue_ENGskill

This repository is meant to compare the complexity of 2 type of Piority queue implementation which is skew heap and Linked List. The simulation will run with 3 input data pattern and each data patten will run 3 times. Eventually the result will be produced as the mean of the 3*3 simulation. 

How to Compile:
Run make in the repository root path

How to run simulation:
Run ./plot.sh <#number of item> <#ifference between data point> and wait for simulation complete. The result will be output into the /plot/ folder and named as heap.jpg.
or
If only need the create the graph under previous  simulation results under plot folder, run ./just_plot.sh. NOT WORKING FOR THE NEWEST VERSION

Run implementation individually:

Skew Heap:
./run_heap "<#Number of item> <#difference between data point> <#debug switch>"
  
Linked List:
./run_list "<#Number of item> <#difference between data point> <#debug switch>"
  

To active debug:
debug switch in ./run_list.sh or ./run_heap.sh has 2 state

0 - debug off (in plot.sh is madatory to switch off the debug for data accuracy)	

1 - debug on

Currently issue:

1.Skew heap implementation has memory leak

2.SonarQube issue has not been fixed yet

3.Second draft of report is pending..... 

