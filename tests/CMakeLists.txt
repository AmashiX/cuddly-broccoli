add_executable(
        tests
        ${PROJECT_SOURCE_DIR}/Vecteur.h
        tests.cpp

)

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        tests
        gtest_main
        gtest
        pthread
)

include(GoogleTest)

gtest_discover_tests(tests)
