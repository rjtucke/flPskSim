CXX = g++
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -O3
LINKFLTK = $(shell fltk-config --ldstaticflags --use-images)

STRIP       = strip
POSTBUILD   = fltk-config --post # Required on OS X

all: flPskSim

main.o: main.cc
	$(CXX) -c $< $(CXXFLAGS)

flPskSim:   main.o
	$(CXX) -o $@ main.o $(LINKFLTK)
	$(STRIP) $@
	$(POSTBUILD) $@
