find_package(OpenSSL REQUIRED)

add_library(openssl INTERFACE)

target_link_libraries(openssl
  INTERFACE
    ${OPENSSL_LIBRARIES}
)

target_include_directories(openssl
  INTERFACE
    ${OPENSSL_INCLUDE_DIR}
)
