# Include the main project headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# List all test files
set(TEST_SOURCES
    test_kmeans.cpp
)

# Loop through each test source and create an executable
foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)  # Extract test name
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE kmeans)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()