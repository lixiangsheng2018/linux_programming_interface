add_executable(readv ${CMAKE_CURRENT_SOURCE_DIR}/readv.cpp)
target_link_libraries(readv
	PRIVATE myc
)

add_executable(large_file ${CMAKE_CURRENT_SOURCE_DIR}/large_file.cpp)
target_link_libraries(large_file
	PRIVATE myc
)

add_executable(vector_fileio ${CMAKE_CURRENT_SOURCE_DIR}/vector_fileio.cpp)
