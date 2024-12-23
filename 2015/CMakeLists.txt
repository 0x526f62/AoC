add_executable(Day01 Day01.c)
add_custom_command(TARGET Day01 PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Day01Input.txt ${CMAKE_CURRENT_BINARY_DIR}/Day01Input.txt
	COMMENT "Copy Input for Day01"
)

add_custom_command(TARGET Day01 POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E ${CMAKE_CURRENT_BINARY_DIR}/Day01.exe
	DEPENDS Day01
	COMMENT "Running Day01.exe"
)

