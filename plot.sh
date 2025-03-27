#!/bin/bash

cat $1 | tail -n +2 > /tmp/plotdata
echo "e" >> /tmp/plotdata

echo "set term dumb size 80 21 ansirgb; set autoscale; set key opaque; set key left top; set xlabel 'n'; set ylabel 'time (s)'; set datafile separator \",\"; plot '-' using 1:2 with points pt '#' title 'DyV', '' using 1:3 with points pt '*' title 'direct';" | cat - /tmp/plotdata /tmp/plotdata | gnuplot -p

