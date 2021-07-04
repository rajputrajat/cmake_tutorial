cmake_minimum_required(VERSION 3.20.4)

project(CMK VERSION 0.1)

configure_file(cmk_config.h.in cmk_config.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(adder)

# download all the submodules
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # update submodules as needed
    option(GIT_SUBMODULE "check submodules during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please check")
        endif()
    endif()
endif()

# check all the submodules
if (NOT EXISTS ${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt)
    message(FATAL_ERROR "the glfw submodule wasn't downloaded")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PRIVATE adder
    PRIVATE external/glfw/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE adder
    PRIVATE glfw
)
