plot.png: datos.dat graficas.py
	python graficas.py

%.dat : a.out
	./a.out

a.out: codigo.cpp
	g++ codigo.cpp

# clean

clean : 
	@rm -f *.dat *.png *.out
