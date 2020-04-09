add_executable(Launcher ${CMAKE_CURRENT_SOURCE_DIR}/Launcher.cpp)

target_include_directories(Launcher
  PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Launcher
  PRIVATE
    Shared
)

#if (MSVC)
#   set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/PCH.cpp PROPERTIES COMPILE_FLAGS "/YcPCH.h")
#   set_target_properties(SSandbox PROPERTIES COMPILE_FLAGS "/YuPCH.h")
#endif(MSVC)

#install(TARGETS SSandbox RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)
