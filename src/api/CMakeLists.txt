cmake_minimum_required(VERSION 3.10)
project(test)

find_package(oatpp REQUIRED)
find_package(oatpp-postgresql REQUIRED)

add_executable(main main.cpp)
target_link_libraries(
    main 
    oatpp::oatpp
    oatpp::oatpp-postgresql
)