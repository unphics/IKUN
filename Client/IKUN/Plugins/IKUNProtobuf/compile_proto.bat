@echo off

.\Source\ThirdParty\Protobuf\lib\protoc.exe --proto_path=..\..\..\Protos\ --cpp_out=..\..\Source\IKUN\Public\Protos\ Test.proto

pause