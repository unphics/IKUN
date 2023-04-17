:: echo off：关闭回显，批处理中的每一条命令都不会显示在显示器上。而echo off本身也是一条命令，如果不想让其显示，只需在前方加@符号即可。
@echo off

:: protobuf-vcpkg-thirdparty
:: %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --proto_path=../../Source/IKUNProtos/proto/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: protobuf-vcpkg-environment
:: /r表示自动遍历子目录，%%i表示声明一个i，in ()表示遍历的目录，%VCPKG_ROOT%是环境变量，
:: for /r %%i in (../../Source/IKUNProtos/proto/*.proto) do (
:: 	 %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --cpp_out=../../../Source/IKUNProtos/Public/ --proto_path=../../Source/IKUNProtos/proto/%%~ni.proto
:: 	 pause
:: )
:: echo %VCPKG_ROOT%
:: /s表示复制子目录，/y表示不提示是否覆盖已有文件
:: xcopy ../../Source/IKUNProtos/Public/*.cc ../../Source/IKUNProtos/Private/ /S /E /Y

:: protobuf-3.20.2-thirdparty-IKUNProtosModule
:: .\Source\ThirdParty\Protobuf\lib\protoc.exe --proto_path=../../Source/IKUNProtos/Protos/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: SET的等号左右两边不能有空格
:: SET CUR_PATH=%cd%
:: for /r %%i in (../../Source/IKUNProtos/Proto/*.proto) do (
::  	.\Source\ThirdParty\Protobuf\lib\protoc.exe --proto_path=..\..\Source\IKUNProtos\Protos\%%~ni.proto --cpp_out=..\..\Source\IKUN\Public\Protos\
::)


echo 完了
pause