file (GLOB_RECURSE PRIVATE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

get_subdirectories(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

add_library(proto
  ${PRIVATE_FILES}
)

target_include_directories(proto
  PUBLIC
    ${INCLUDE_DIRECTORIES}
)

target_link_libraries(proto
  PUBLIC
    libprotobuf
)

if (MSVC)
   set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/protoPCH.cpp PROPERTIES COMPILE_FLAGS "/YcprotoPCH.h")
   #set_target_properties(proto PROPERTIES COMPILE_FLAGS "/YuprotoPCH.h")
endif(MSVC)

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(proto PRIVATE "-Wnone")
endif()
if (MSVC)
    target_compile_options(proto PRIVATE "/W0")
endif()
