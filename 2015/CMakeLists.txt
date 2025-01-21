include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(2015-Day01 Day01.c "Day01.c" "Day03.c")
set(DAY01_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Day01Input.txt")
add_custom_command(TARGET 2015-Day01 POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "====== Running 2015-Day01 ======")
add_custom_command(TARGET 2015-Day01 POST_BUILD COMMAND 2015-Day01 ${DAY01_FILE} COMMENT "Running 2015-Day01.exe")

add_executable(2015-Day02 Day02.c "Day02.c" "Day03.c")
set(DAY02_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Day02Input.txt")
add_custom_command(TARGET 2015-Day02 POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "====== Running 2015-Day02 ======")
add_custom_command(TARGET 2015-Day02 POST_BUILD COMMAND 2015-Day02 ${DAY02_FILE} )
