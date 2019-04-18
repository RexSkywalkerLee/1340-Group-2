sign.o: sign.cpp recordsManipulation.h
	g++ -pedantic-errors -std=c++11 -c $<
recordsManipulation.o: recordsManipulation.cpp recordsManipulation.h
	g++ -pedantic-errors -std=c++11 -c $<
main.o: main.cpp recordsManipulation.h
	g++ -pedantic-errors -std=c++11 -c $<
main: sign.o main.o recordsManipulation.o
	g++ $^ -o $@
clean:
	rm *.o main
erase:
	rm *.txt
.PHONY: clean erase
