set (protobuf_source_dir ${CMAKE_CURRENT_SOURCE_DIR})
set (protobuf_VERSION "3.6.1")
set (protobuf_SHARED_OR_STATIC "STATIC")
set (protobuf_BUILD_SHARED_LIBS, OFF)
include(libprotobuf-lite.cmake)
include(libprotobuf.cmake)

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(libprotobuf PRIVATE "-Wnone")
    #target_compile_options(libprotobuf-lite PRIVATE "-Wnone")
endif()
if (MSVC)
    target_compile_options(libprotobuf PRIVATE "/W0")
    #target_compile_options(libprotobuf-lite PRIVATE "/W0")
endif()


#include(libprotoc.cmake)
