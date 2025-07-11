set title 'K-Means Clustering Result'
set xlabel 'X Coordinate'
set ylabel 'Y Coordinate'
set palette defined (0 'red', 1 'green', 2 'blue', 3 'yellow', 4 'purple')
plot 'plotFile.txt' using 1:2:3 with points palette pointtype 7 pointsize 1 title 'Clusters'
pause -1
