include(FetchContent)
find_package(OpenSSL)

FetchContent_Declare(
    libhv
    GIT_REPOSITORY https://github.com/ithewei/libhv
    GIT_TAG v1.3.3
)

FetchContent_MakeAvailable(libhv)

include_directories(${libhv_BINARY_DIR}/include/hv)

add_executable(qsh-server main.cpp)

target_link_libraries(qsh-server hv OpenSSL::Crypto)
