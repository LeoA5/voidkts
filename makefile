CXX = g++
MYSQL = mariadb_config

CXXFLAGS = $(shell $(MYSQL) --cflags)
LDFLAGS = $(shell $(MYSQL) --libs)

main: src/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)