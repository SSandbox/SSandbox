#
#  MILLENIUM-STUDIO
#  Copyright 2016 Millenium-studio SARL
#  All Rights Reserved.
#

if(UNIX)
  # Look for an installed zlib on unix
  find_package(ZLIB REQUIRED)

  add_library(zlib SHARED IMPORTED GLOBAL)

  set_target_properties(zlib
    PROPERTIES
      IMPORTED_LOCATION
        "${ZLIB_LIBRARIES}"
      INTERFACE_INCLUDE_DIRECTORIES
        "${ZLIB_INCLUDE_DIRS}")
else()
  # Use the bundled source on windows
  SET(zlib_STAT_SRCS
    adler32.c
    compress.c
    crc32.c
    deflate.c
    infback.c
    inffast.c
    inflate.c
    inftrees.c
    trees.c
    uncompr.c
    zutil.c
  )

  add_library(zlib STATIC
    ${zlib_STAT_SRCS})

  target_include_directories(zlib
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR})

  set_target_properties(zlib
      PROPERTIES
        FOLDER
          "dep")
endif()
