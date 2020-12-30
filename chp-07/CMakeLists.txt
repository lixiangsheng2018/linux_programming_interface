add_executable(free_and_sbrk ${CMAKE_CURRENT_SOURCE_DIR}/free_and_sbrk.cpp)
target_link_libraries(free_and_sbrk
	PRIVATE myc
)