otherFunctions.o: otherFunctions.cpp
	g++ -pedantic-errors -std=c++11 -c $<
accounts.o: accounts.cpp
	g++ -pedantic-errors -std=c++11 -c $<
records.o: records.cpp 
	g++ -pedantic-errors -std=c++11 -c $<
budget.o: budget.cpp
	g++ -pedantic-errors -std=c++11 -c $<
report.o: report.cpp
	g++ -pedantic-errors -std=c++11 -c $<
latest.o: latest.cpp
	g++ -pedantic-errors -std=c++11 -c $<
main.o: main.cpp
	g++ -pedantic-errors -std=c++11 -c $<
main: main.o otherFunctions.o records.o accounts.o budget.o report.o latest.o
	g++ $^ -o $@
clean:
	rm *.o main
erase:
	rm *.txt
.PHONY: clean erase
