@echo off
set PROTO_DIR=proto
set OUT_DIR=generated
set GEN_DIR=C:/project/c++/vcpkg/installed/x64-windows/tools/grpc
rem protoc가 PATH에 있다고 가정
protoc -I %PROTO_DIR% --cpp_out=%OUT_DIR% %PROTO_DIR%\hello.proto
protoc -I proto --grpc_out=generated --plugin=protoc-gen-grpc=%GEN_DIR%/grpc_cpp_plugin.exe proto\hello.proto
echo === gRPC Proto compiled Succ ===