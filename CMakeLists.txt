cmake_minimum_required(VERSION 3.12)
project(ZMQ_Comms)

set(CMAKE_CXX_STANDARD 14)

# Enable colorized diagnostics
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=auto")

# Automatically find all .cpp files in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
message(STATUS "Source files: ${SOURCES}")

# Create executable using all found sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Asio
add_definitions(-DASIO_STANDALONE)  # Standalone mode (no Boost dependency)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/lib/asio/asio/include
        
)

# Find ZeroMQ and cppzmq
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZMQ REQUIRED IMPORTED_TARGET libzmq)
find_package(cppzmq REQUIRED)

#Link libraries
target_link_libraries(${PROJECT_NAME} 
PRIVATE PkgConfig::ZMQ cppzmq

PRIVATE pthread     # Required for Asio thread support
PRIVATE rt          # Required for some POSIX features
)
