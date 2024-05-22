all: main

# compile le projet, peut etre appeler par make main, make all ou make
main: build build/chiffrement.o build/affichage.o build/verif.o
	gcc -I include -g -o build/main build/affichage.o build/chiffrement.o build/verif.o

# chiffrement, affichage, verif et test compile le fichiers source qui lui correspond
build/chiffrement.o: src/chiffrement.c
	gcc -I include -c src/chiffrement.c -o build/chiffrement.o

build/affichage.o: src/affichage.c
	gcc -I include -c src/affichage.c -o build/affichage.o

build/verif.o: src/verif.c
	gcc -I include -c src/verif.c -o build/verif.o

build/test.o: test/test.c
	gcc -I include -c test/test.c -o build/test.o

# crée le dossier build s'il n'existe pas
build:
	[ -f build ] || mkdir build

# supprime les fichiers objets du dossier build
clean-build:
	rm -r build/*.o

# supprime les fichiers objets et exécutable du dossier build
clean: clean-build
	rm -r build/*

# compile et lance le projet 
run: main
	./build/main

# compile les tests
compile-test: build build/test.o build/chiffrement.o build/verif.o
	gcc -I include -g -o build/test build/chiffrement.o build/verif.o build/test.o 

# compile et lance les tests
test: compile-test
	./build/test

# crée l'archive du projet a envoyer sur moodle
archive: clean
	zip -r Sujet3_KOH1_LFARH2.zip *
