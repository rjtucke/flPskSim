CXX = g++
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -O3
LINKFLTK = $(shell fltk-config --ldstaticflags --use-images)
INC = -I ./

STRIP       = strip
POSTBUILD   = fltk-config --post # Required on OS X

all: flPskSim

main.o: main.cc
	$(CXX) -c $< $(CXXFLAGS)

Panel.o: Panel.cxx
	$(CXX) -I./include -c $< $(CXXFLAGS)

flPskSim:   main.o Panel.o
	$(CXX) -o $@ main.o Panel.o $(LINKFLTK)
	$(STRIP) $@
	$(POSTBUILD) $@
