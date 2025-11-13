# === Makefile ===

# Compiler and flags
CXX      := clang++
CXXFLAGS := -std=c++17 -g -Wall -Wextra

# Source files for reusable code
COMMON_SRC := Cdb.cpp Interface.cpp

# Programs to build
PROGRAMS := main test_cdb test_interface

# Build all by default
all: $(PROGRAMS)

# Build rules for each program
main: main.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

test_cdb: test_cdb.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

test_interface: test_interface.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run targets (optional convenience)
run_main: main
	./main

run_cdb: test_cdb
	./test_cdb

run_interface: test_interface
	./test_interface

# Clean up
clean:
	rm -f $(PROGRAMS)