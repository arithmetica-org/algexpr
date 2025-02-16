cmake_minimum_required(VERSION 3.29)

project(algparse)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories("/usr/local/include")
link_directories("/usr/local/lib")

set(SOURCES algexpr.cpp
            to_string.cpp
            deep_copy.cpp
            decompose_into_terms.cpp
	    decompose_into_products.cpp
	    math_operators.cpp
	    comparasion_operators.cpp
            distribute_exponent_over_product.cpp
	    distribute_exponent_over_sum.cpp
	    simplify_term.cpp
            numeric_checks.cpp
	    evaluate_multiplication.cpp
            combine_like_terms.cpp
	    simplify.cpp
            main.cpp)

add_executable(algparse ${SOURCES})

target_link_libraries(algparse basic_math_operations)
target_link_libraries(algparse arithmetica)

