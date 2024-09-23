#OpenSSL usage Makefile
CXX		 		= g++
CXXFLAGS 		= -Wall -std=c++17
DEBUG			= -g
TARGET	 		= sample
SRC		 		= sample.cpp
INCLUDE_DIRS	= /usr/local/include/openssl
LIB				= -lssl -lcrypto

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(SRC) $(LIB) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)