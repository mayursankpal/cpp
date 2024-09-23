# Producer Consumer Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = producer_consumer
SRC		 = producer_consumer.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)