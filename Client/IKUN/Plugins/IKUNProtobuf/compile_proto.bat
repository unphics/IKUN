:: echo off���رջ��ԣ��������е�ÿһ�����������ʾ����ʾ���ϡ���echo off����Ҳ��һ������������������ʾ��ֻ����ǰ����@���ż��ɡ�
@echo off

:: protobuf-vcpkg-thirdparty
:: %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --proto_path=../../Source/IKUNProtos/proto/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: protobuf-vcpkg-environment
:: /r��ʾ�Զ�������Ŀ¼��%%i��ʾ����һ��i��in ()��ʾ������Ŀ¼��%VCPKG_ROOT%�ǻ���������
:: for /r %%i in (../../Source/IKUNProtos/proto/*.proto) do (
:: 	 %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --cpp_out=../../../Source/IKUNProtos/Public/ --proto_path=../../Source/IKUNProtos/proto/%%~ni.proto
:: 	 pause
:: )
:: echo %VCPKG_ROOT%
:: /s��ʾ������Ŀ¼��/y��ʾ����ʾ�Ƿ񸲸������ļ�
:: xcopy ../../Source/IKUNProtos/Public/*.cc ../../Source/IKUNProtos/Private/ /S /E /Y

:: protobuf-3.20.2-thirdparty-IKUNProtosModule
:: .\Source\ThirdParty\Protobuf\lib\protoc.exe --proto_path=../../Source/IKUNProtos/Protos/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: SET�ĵȺ��������߲����пո�
:: SET CUR_PATH=%cd%
:: for /r %%i in (../../Source/IKUNProtos/Proto/*.proto) do (
::  	.\Source\ThirdParty\Protobuf\lib\protoc.exe --proto_path=..\..\Source\IKUNProtos\Protos\%%~ni.proto --cpp_out=..\..\Source\IKUN\Public\Protos\
::)


echo ����
pause