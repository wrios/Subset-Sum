CXX=g++
CC_FLAGS = -fPIC -Wall
CFLAGS= -std=c++11

all: factibilidad fb optimalidad pd

factibilidad: Factibilidad.cpp
	$(CXX) Factibilidad.cpp $(CFLAGS) -o $@

fb: FB.cpp
	$(CXX) FB.cpp $(CFLAGS) -o $@

optimalidad: Optimalidad.cpp
	$(CXX) Optimalidad.cpp $(CFLAGS) -o $@

pd: PD.cpp
	$(CXX) PD.cpp $(CFLAGS) -o $@

clean:
	rm -f *.o
	rm -f factibilidad fb optimalidad pd
	

