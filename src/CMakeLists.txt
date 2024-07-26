set(PROGRAM_NAME fb)

add_executable(${PROGRAM_NAME} "main.cpp")

set (
    FB_TP_LIB
    tlog
)

set(
    FB_THIRD_PARTY_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/third_party/cxxopts/include
    ${PROJECT_SOURCE_DIR}/third_party/tlog/include/tlog
)

include_directories(${FB_THIRD_PARTY_INCLUDE_DIR})

target_link_libraries(${PROGRAM_NAME} ${FB_TP_LIB})