include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

file(GLOB DAY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(DAY_SOURCE ${DAY_SOURCES})
get_filename_component(DAY_NAME ${DAY_SOURCE} NAME_WE) 

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${DAY_NAME}.i
    COMMAND ${CMAKE_CXX_COMPILER} /P ${DAY_SOURCE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Preprocessing ${DAY_NAME}"
)
add_custom_target(preprocess DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${DAY_NAME}.i)

add_executable(${DAY_NAME} ${DAY_SOURCE})
add_dependencies(${DAY_NAME} preprocess)
target_compile_options(${DAY_NAME} PRIVATE /wd4996)
add_custom_command(TARGET ${DAY_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${DAY_NAME}> "${CMAKE_CURRENT_SOURCE_DIR}/${DAY_NAME}.exe")
#add_custom_command(TARGET 2015-${DAY_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "====== Running 2015-${DAY_NAME} ======")
#add_custom_command(TARGET 2015-${DAY_NAME} POST_BUILD COMMAND 2015-${DAY_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/${DAY_NAME}Input.txt" )
endforeach()


