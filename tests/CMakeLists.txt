cmake_minimum_required (VERSION 3.13.0)

project(test-string)

add_executable(${PROJECT_NAME} "") 

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

find_package(corgi-test CONFIG)


if(MSVC)
target_compile_options(${PROJECT_NAME} PRIVATE -W3 )
else()
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)
endif()

target_link_libraries(${PROJECT_NAME} corgi-test corgi-string)

set_property(TARGET ${PROJECT_NAME}  PROPERTY CXX_STANDARD 20)

add_test( NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
