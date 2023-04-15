@echo off

%VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --proto_path=../../Source/IKUNProtos/proto/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: /r表示自动遍历子目录，%%i表示声明一个i，in ()表示遍历的目录，%VCPKG_ROOT%是环境变量，
:: for /r %%i in (../../Source/IKUNProtos/proto/*.proto) do (
:: 	 %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --cpp_out=../../../Source/IKUNProtos/Public/ --proto_path=../../Source/IKUNProtos/proto/%%~ni.proto
:: 	 pause
:: )
:: echo %VCPKG_ROOT%
:: /s表示复制子目录，/y表示不提示是否覆盖已有文件
:: xcopy ../../Source/IKUNProtos/Public/*.cc ../../Source/IKUNProtos/Private/ /S /E /Y

pause