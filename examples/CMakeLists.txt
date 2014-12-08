include_directories (${CMAKE_SOURCE_DIR}/src)

add_executable (cosy1 cosy1.cc)
target_link_libraries (cosy1 gamma)