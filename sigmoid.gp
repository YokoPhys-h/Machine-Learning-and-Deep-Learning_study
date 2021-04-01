set datafile separator " "
set key right bottom
#set size ratio 1
#set logscale y
set mxtics
set mytics
set ylabel "$y$"
set xlabel "$x$"

#set format x "%g"



f(x)=1/(1+exp(-x))
#fit [0.1:2] f(x) "means_0.dat" using 1:2 via a,b

#plot "means_0.dat" using 1:2 with points pointtype 7 lc 1 title "$\\phi_{pr}$"
plot f(x) lc 7 linewidth 2 title "sugmoid funtion"

#set term lua tikz size 12cm, 8cm font '\footnotesize'
#set output "means_PHI-1.tex"
#replot

set terminal windows
set output