# Thread Pool Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall
TARGET	 = thread_pool
SRC		 = thread_pool.cpp
LDLIBS	 = -lboost_system
INCLDIR  = /usr/local/boost_1_86_0/

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -I $(INCLDIR) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)