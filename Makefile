all:
	gcc -ggdb -Wall --pedantic src/*.c -o bin/gauss

test1:
	@echo "Test 1: 2x2, poprawne dane wejsciowe, uklad oznaczony, element zerowy na przekatnej"
	@bin/gauss test/1/A test/1/b > test/wynik
	@a=`diff -wq test/1/w test/wynik`
	@[ -z $a ] && echo "Wynik: OK" || "Wynik: Blad!"

test2:
	@echo "Test 2: 4x4, poprawne dane wejsciowe, uklad oznaczony"
	@bin/gauss test/2/A test/2/b > test/wynik
	@a=`diff -wq test/2/w test/wynik`
	@[ -z $a ] && echo "Wynik: OK" || "Wynik: Blad!"

test3:
	@echo "Test 3: 2x2, macierz osobliwa"
	@bin/gauss test/3/A test/3/b > test/wynik
	@a=`diff -wq test/3/w test/wynik`
	@[ -z $a ] && echo "Wynik: OK" || "Wynik: Blad!"

test4:
	@echo "Test 4: 3x2, zly rozmiar macierzy - rzad Ab rozny od rzedu A"
	@bin/gauss test/4/A test/4/b > test/wynik
	@a=`diff -wq test/4/w test/wynik`
	@[ -z $a ] && echo "Wynik: OK" || "Wynik: Blad!"


test: test1 test2 test3 test4

