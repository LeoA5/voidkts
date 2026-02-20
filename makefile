CXX = g++

MYSQL = mariadb_config
CXXFLAGS += $(shell $(MYSQL) --cflags) 
LDFLAGS = $(shell $(MYSQL) --libs) 

App: src/App.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)