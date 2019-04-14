sign: sign.cpp
	g++ -pedantic-errors -std=c++11 $^ -o $@
clean:
	rm sign
erase:
	rm *.txt
.PHONY: clean erase
