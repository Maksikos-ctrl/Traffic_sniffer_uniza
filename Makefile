CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LDFLAGS = -ltins

SRC = main.cpp
EXEC = packet_sniffer

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC) $(LDFLAGS)

clean:
	rm -f $(EXEC)

.PHONY: all clean
