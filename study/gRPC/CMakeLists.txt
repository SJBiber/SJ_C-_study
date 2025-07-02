cmake_minimum_required(VERSION 3.15)
project(grpc_hello LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# proto 경로
set(PROTO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
set(PROTO_FILE "${PROTO_DIR}/hello.proto")
set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../gRPC/generated")

# vcpkg toolchain은 cmake 호출 시 지정
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# proto 파일로부터 소스코드 생성 (수동 호출하는 방법 권장)
# 만약 자동 함수가 작동 안 하면, 수동으로 protoc 빌드 권장

# 컴파일 대상
add_executable(server 
    server/server.cpp
    ${GENERATED_DIR}/hello.pb.cc
    ${GENERATED_DIR}/hello.grpc.pb.cc)
add_executable(client 
    client/client.cpp
    ${GENERATED_DIR}/hello.pb.cc
    ${GENERATED_DIR}/hello.grpc.pb.cc)

# include 경로
target_include_directories(server PRIVATE ${PROTO_DIR} ${Protobuf_INCLUDE_DIRS} ${GENERATED_DIR})
target_include_directories(client PRIVATE ${PROTO_DIR} ${Protobuf_INCLUDE_DIRS} ${GENERATED_DIR})

# 링크 라이브러리
target_link_libraries(server PRIVATE gRPC::grpc++ protobuf::libprotobuf)
target_link_libraries(client PRIVATE gRPC::grpc++ protobuf::libprotobuf)

