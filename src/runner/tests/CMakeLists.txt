set(RUNNER_TEST_PROJECT_NAME "${RUNNER_PROJECT_NAME}_tests")

add_executable(
    "${RUNNER_TEST_PROJECT_NAME}"
    main.cpp
    runner.cpp
)

target_link_libraries(
    "${RUNNER_TEST_PROJECT_NAME}"
    Catch2::Catch2
)

target_include_directories(
    "${RUNNER_TEST_PROJECT_NAME}"
    SYSTEM PRIVATE
    "${CATCH2_INCLUDE_DIRS}"
)

set("TEST_DATA_DIRECTORY" "${CMAKE_CURRENT_LIST_DIR}")

catch_discover_tests("${RUNNER_TEST_PROJECT_NAME}")
