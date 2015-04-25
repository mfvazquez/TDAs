#! /bin/sh
export TIME="Tardo: %U s - Consumio: %M kB" 

for i in 12500 25000 50000; do
	echo -n "$i elementos - ";
	time $1 $i
done
