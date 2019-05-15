hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/DaireselBagilListe.o -c ./src/DaireselBagilListe.cpp
	g++ -I ./include/ -o ./bin/main ./src/main.cpp
	
calistir:
	./bin/main.exe