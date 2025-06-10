add_executable(adjacency_multilist_main adjacency_multilist_main.cpp)
add_executable(MST_main MST_main.cpp)
add_executable(SCC_main SCC_main.cpp)

target_include_directories(adjacency_multilist_main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MST_main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(SCC_main PRIVATE ${CMAKE_SOURCE_DIR}/include)