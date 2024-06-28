set(
    TLOG_INCLUDE
    ${PROJECT_SOURCE_DIR}/src/include/tlog
    ${PROJECT_SOURCE_DIR}/third_party/fmt/include
)

set(
    TLOG_SRC
    tlog.cpp
)

include_directories(${TLOG_INCLUDE})

add_library(tlog OBJECT ${TLOG_SRC})
target_link_libraries(tlog fmt)