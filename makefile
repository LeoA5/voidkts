CXX = g++

MYSQL = mariadb_config
CXXFLAGS += $(shell $(MYSQL) --cflags) 
LDFLAGS = $(shell $(MYSQL) --libs) 

App: src/backend/app.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)