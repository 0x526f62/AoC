include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
add_executable(Day01 Day01.c)
add_custom_command(TARGET Day01 PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Day01Input.txt ${CMAKE_CURRENT_BINARY_DIR}/Day01Input.txt
	COMMENT "Copy Input for Day01"
)

add_custom_command(TARGET Day01 POST_BUILD 
	COMMAND Day01 ${CMAKE_CURRENT_BINARY_DIR}/Day01Input.txt
	COMMENT "Running Day01.exe"
)

