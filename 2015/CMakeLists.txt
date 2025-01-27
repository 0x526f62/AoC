include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

file(GLOB DAY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(DAY_SOURCE ${DAY_SOURCES})
get_filename_component(DAY_NAME ${DAY_SOURCE} NAME_WE) 
add_executable(2015-${DAY_NAME} ${DAY_SOURCE})
target_compile_options(2015-${DAY_NAME} PRIVATE /wd4996)
#add_custom_command(TARGET 2015-${DAY_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "====== Running 2015-${DAY_NAME} ======")
#add_custom_command(TARGET 2015-${DAY_NAME} POST_BUILD COMMAND 2015-${DAY_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/${DAY_NAME}Input.txt" )
endforeach()


