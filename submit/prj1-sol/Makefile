CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OFILE = main.cpp

TARGET = wordcounts

all:		clean $(TARGET)

$(TARGET):	$(OFILE)
		$(CXX) $(CXXFLAGS) $(OFILE) -o $@

clean:
		rm -f *~ *.o $(TARGET)
