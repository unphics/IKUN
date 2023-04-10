@echo off
echo %VCPKG_ROOT%

%VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --proto_path=./proto/ --cpp_out=../Protos/ Test.proto

pause