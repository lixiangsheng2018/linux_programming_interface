add_executable(copy ${CMAKE_CURRENT_SOURCE_DIR}/copy.cpp)
target_link_libraries(copy
	PRIVATE myc
)

add_executable(server ${CMAKE_CURRENT_SOURCE_DIR}/signal_io/server.cpp)
set_target_properties(server
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/chp-04/signal_io"
)
target_link_libraries(server
	PRIVATE myc
)
add_executable(clent ${CMAKE_CURRENT_SOURCE_DIR}/signal_io/client.cpp)
set_target_properties(clent
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/chp-04/signal_io"
)
target_link_libraries(clent
	PRIVATE myc
)
add_executable(seek_io ${CMAKE_CURRENT_SOURCE_DIR}/seek_io.cpp)
target_link_libraries(seek_io
	PRIVATE myc
)

add_executable(tee ${CMAKE_CURRENT_SOURCE_DIR}/tee.cpp)
add_executable(cpholes ${CMAKE_CURRENT_SOURCE_DIR}/cpholes.cpp)
target_link_libraries(cpholes
	PRIVATE myc
)

