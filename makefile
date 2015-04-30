main:main.o
	g++ -std=c++11 main.cpp Zcal.cpp RPolish.cpp
clean:
	rm -fr *.o main
