CXX = g++
CXXFLAGS = -g -Wall -std=c++17

CXX_FILES = $(wildcard *.cc)

OFILES = $(CXX_FILES:cc=o)

all:		clean seq-test nums

seq-test:	$(OFILES)
	$(CXX) $(CXXFLAGS) command.o seq-test.o -o $@

nums: $(OFILES)
	$(CXX) $(CXXFLAGS) nums.o command.o -o $@

clean:
	rm -f *~ *.o seq-test nums
