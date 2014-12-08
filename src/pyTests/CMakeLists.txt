if (ENABLE_PYGAMMA)
  add_test (NAME pytest
    COMMAND ${PYTHON_EXECUTABLE} ../Tests/run_tests.py -v
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
  set_property (
    TEST pytest
    PROPERTY ENVIRONMENT "PYTHONPATH=${PROJECT_BINARY_DIR}/src/"
    )
endif (ENABLE_PYGAMMA)
