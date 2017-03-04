set title ''
set logscale x 10
set term png enhanced font 'Verdana,10'
set output 'result.png'

plot "data.txt" using 1:2 w lines title 'baseline',\
     "data.txt" using 1:3 w lines title 'OpenMp(2 threads)',\
     "data.txt" using 1:4 w lines t 'OpenMp(4 threads)',\
     "data.txt" using 1:5 w lines title 'AVX',\
     "data.txt" using 1:6 w lines t 'AVX + unroll looping'