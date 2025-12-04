# Makefile for CSC-301 Project #5
# Eric A. Autry, 09/08/22
# 
# As usual, you can build this software by typing:
#
#     make


# ----- Make Macros -----

CXXFLAGS =	-O3
CXX	=	clang

TARGETS =	testEdits
OBJECTS =	testEdits.cpp project5.cpp Edit.cpp
REMOVE =	testEdits.o project5.o Edit.o
LINKS =	-std=c++20 -lstdc++ -lm
INCLUDE = 

# ----- Make Rules -----

all:	$(TARGETS)

testEdits:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o testEdits $(OBJECTS) $(LINKS)

clean:
	rm -f $(TARGETS) $(REMOVE)