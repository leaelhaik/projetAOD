#/bin/bash

for j in {1..5}
do
	{ /usr/bin/time -f "%e real" ./bin/compileBST 1000 benchmarks/benchmark1.in > /dev/null; } 2>> log3.txt

	#On récupère seulement le nombre flottant correspondant au temps passé
	cat log3.txt|grep -oE "\-?[0-9]+\.[0-9]+" > result3.txt
done
for j in {1..5}
do
	{ /usr/bin/time -f "%e real" ./bin/compileBST 2000 benchmarks/benchmark1.in > /dev/null; } 2>> log4.txt

	#On récupère seulement le nombre flottant correspondant au temps passé
	cat log4.txt|grep -oE "\-?[0-9]+\.[0-9]+" > result4.txt
done
for j in {1..5}
do
	{ /usr/bin/time -f "%e real" ./bin/compileBST 3000 benchmarks/benchmark1.in > /dev/null; } 2>> log5.txt

	#On récupère seulement le nombre flottant correspondant au temps passé
	cat log5.txt|grep -oE "\-?[0-9]+\.[0-9]+" > result5.txt
done
for j in {1..5}
do
	{ /usr/bin/time -f "%e real" ./bin/compileBST 5000 benchmarks/benchmark1.in > /dev/null; } 2>> log6.txt

	cat log6.txt|grep -oE "\-?[0-9]+\.[0-9]+" > result6.txt
done
