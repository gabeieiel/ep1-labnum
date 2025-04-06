set terminal png size 500,500;
set output 'bacias.png';
set view map;
unset key;
unset xtics;
unset ytics;
set palette defined (0 'red', 1 'blue', 2 'green', 3 'purple', 4 'orange');
plot 'output.txt' matrix with image;