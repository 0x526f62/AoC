include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(Day01 Day01.c)
set(DAY01_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Day01Input.txt")
#target_compile_definitions(Day01 PRIVATE DAY01_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Day01Input.txt")
add_custom_command(TARGET Day01 POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "====== Running Day01 ======")
add_custom_command(TARGET Day01 POST_BUILD COMMAND Day01 ${DAY01_FILE} COMMENT "Running Day01.exe")
add_custom_command(TARGET Day01 POST_BUILD 
COMMAND ${CMAKE_COMMAND} -E echo "====== setting up debug config ======"
COMMAND ${CMAKE_COMMAND} -E make_directory "${VS_CONFIG_DIR}"
COMMAND ${CMAKE_COMMAND} -E touch "${VS_CONFIG_DIR}/launch.vs.json"
COMMAND ${CMAKE_COMMAND} -E echo "{ \"version\": \"0.2.0\"," > \"${VS_CONFIG_DIR}/launch.vs.json\" 
COMMAND ${CMAKE_COMMAND} -E echo "\"configurations\": [ { \"name\": \"Debug ${TARGET}\"," >> \"${VS_CONFIG_DIR}/launch.vs.json\"
COMMAND ${CMAKE_COMMAND} -E echo "\"type\": \"cppvsdbg\", \"request\": \"launch\", " >> \"${VS_CONFIG_DIR}/launch.vs.json\"
COMMAND ${CMAKE_COMMAND} -E echo "\"program\": \"${CMAKE_CURRENT_BINARY_DIR}/Day01.exe\", " >> \"${VS_CONFIG_DIR}/launch.vs.json\"
COMMAND ${CMAKE_COMMAND} -E echo "\"args\": [\"${CMAKE_CURRENT_BINARY_DIR}/Day01Input.txt\"], \"stopAtEntry\": true, " >> \"${VS_CONFIG_DIR}/launch.vs.json\"
COMMAND ${CMAKE_COMMAND} -E echo "\"cwd\": \"${CMAKE_CURRENT_BINARY_DIR}\",\"console\": \"integratedTerminal\" } ] }" >> \"${VS_CONFIG_DIR}/launch.vs.json\"
)

