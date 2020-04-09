find_package(Boost 1.70 REQUIRED system)

add_library(boost INTERFACE)

target_link_libraries(boost
  INTERFACE
    ${Boost_LIBRARIES}
)

target_include_directories(boost
  INTERFACE
    ${Boost_INCLUDE_DIRS}
)

target_compile_definitions(boost
  INTERFACE
    -DBOOST_DATE_TIME_NO_LIB
    -DBOOST_REGEX_NO_LIB
)
