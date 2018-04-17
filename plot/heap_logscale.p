 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap_logscale.png"

set terminal png linewidth 1 size 1360,768  font verdana 24


# This is to set the color
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1

set title "The pefromence of using skew heap vs linked list as pirority queue (logscale)"

set key left top

set xlabel "Number of Application"
set ylabel "Time cost"
set logscale xy

data1 = "<( paste plot/*/heap.dat )"
data2 = "<( paste plot/*/linkedlist.dat )"

f1(x)=a1*x+b1
a1=1
b1=1
fit f1(x) data1 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0) via a1,b1

f2(x)=a2*x+b2
a2=1
b2=1
fit f2(x) data2 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0) via a2,b2

plot data1 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0) w lp pt 6 ps 2 title "skew heap",f1(x) lc rgb "red" title "linefit for skew heap",data2 u 1:(($2+$4+$6+$8+$10+$12+$14+$16+$18)/9.0) w lp pt 6 ps 2 title "linked list",f2(x) lc rgb "red" title "linefit for linkedlist"
