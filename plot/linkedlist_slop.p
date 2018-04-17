 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "linked_derivative.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The slope of pefromence of using linked list as pirority queue"

set key left top

set xlabel "Number of Application"
set ylabel "Time cost"



data2 = "<( paste plot/*/linkedlist.dat )"

x0=NaN
y0=NaN


f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u (dx=$1-x0,x0=$1,$1-dx/2):(dy=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0)-y0,y0=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0),dy/dx) via a2,b2


plot data2 using (dx=$1-x0,x0=$1,$1-dx/2):(dy=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0)-y0,y0=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0),dy/dx) w lp pt 6 ps 2 title "linked list",f2(x) lc rgb "blue" title "linefit for linkedlist slop"
