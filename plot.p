 # Gnuplot script file for plotting data in file "heap.dat"
set terminal png
set output "heap.png"

set terminal png linewidth 4 size 800,600  font verdana 24


# This is to set the color 
set style line 1 lc rgb "black" lw 1 pt 1
set style line 2 lc rgb "red" lw 1 pt 1
set style line 3 lc rgb "blue" lw 1 pt 1

set title ""

set key right center
    
set xlabel "element"
set ylabel "time"    

set xrange [0:100]
set yrange [0:1]


plot "heap.dat" u 1:2 w linespoints ls 2 title "random", ",linkedlist.dat" u 1:2 w linespoints ls 3 title "optimal"
