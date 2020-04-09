file (GLOB_RECURSE PRIVATE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

get_subdirectories(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

file (GLOB_RECURSE SHARED_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Shared/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shared/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Shared/*.hpp
)

add_library(Shared INTERFACE)

target_include_directories(Shared
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Shared
)

add_executable(SSandbox ${PRIVATE_FILES})

target_include_directories(SSandbox
  PRIVATE
    ${INCLUDE_DIRECTORIES}
)

target_link_libraries(SSandbox
  PRIVATE
    boost
    openssl
    proto
    libprotobuf
	zlib
	rapidjson
)

# Protobuf warnings
target_compile_definitions(SSandbox
  PUBLIC
    _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
)

if (MSVC)
   set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/PCH.cpp PROPERTIES COMPILE_FLAGS "/YcPCH.h")
   set_target_properties(SSandbox PROPERTIES COMPILE_FLAGS "/YuPCH.h")
endif(MSVC)


if (MSVC)
  install(TARGETS SSandbox RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)
endif(MSVC)
