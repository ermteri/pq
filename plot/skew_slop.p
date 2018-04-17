 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "skewheap_derivative.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The slope of pefromence of using skew heap "

set key left top

set xlabel "Number of Application"
set ylabel "Time cost"


data1 = "<( paste plot/*/heap.dat )"

x0=NaN
y0=NaN

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u (dx=$1-x0,x0=$1,$1-dx/2):(dy=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0)-y0,y0=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0),dy/dx) via a1,b1


plot data1 using (dx=$1-x0,x0=$1,$1-dx/2):(dy=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0)-y0,y0=(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0),dy/dx) w lp pt 6 ps 2 title "skew heap", f1(x) lc rgb "red" title "linefit for skew heap slop"
