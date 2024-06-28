set(PROGRAM_NAME fb)

add_subdirectory(tlog)

add_executable(${PROGRAM_NAME} "main.cpp")

set (
    FB_LIB
    tlog
)

set(
    FB_THIRD_PARTY_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/third_party/cxxopts/include
)

set(
    FB_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/src/include/tlog
)

include_directories(${FB_THIRD_PARTY_INCLUDE_DIR} ${FB_INCLUDE_DIR})

target_link_libraries(${PROGRAM_NAME} ${FB_LIB})