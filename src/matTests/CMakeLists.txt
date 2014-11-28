if (ENABLE_GAMMAT)
  add_test (NAME mattest
    COMMAND ${PYTHON_EXECUTABLE} ../Tests/run_tests.py -v
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
  set_property (
    TEST mattest
    PROPERTY ENVIRONMENT "PYTHONPATH=${PROJECT_BINARY_DIR}/src/"
    )
endif (ENABLE_GAMMAT)
