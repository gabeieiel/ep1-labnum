set terminal png size 1000,1000;
set output 'bacias.png';

set view map;
unset key;

# mostra tics de -2 a 2, de 1 em 1
set xtics ("0" 0, "1" 200, "2" 400, "3" 6000, "4" 800, "5" 1000)
set ytics ("0" 0, "1" 200, "2" 400, "3" 6000, "4" 800, "5" 1000)

# nomes dos eixos
set xlabel "Re(z)"
set ylabel "Im(z)"

# titulo do gráfico
set title "Bacias de Convergência para f(z) = z^5 + 1 com Método de Newton-Raphson"

# paleta de cores
set palette defined (0 '#0A2463', 1 '#3E92CC', 2 '#FFFAFF', 3 '#D8315B', 4 '#1E1B18');

plot 'output.dat' matrix with image;