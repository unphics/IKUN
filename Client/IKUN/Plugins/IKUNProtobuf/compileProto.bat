@echo off

%VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --proto_path=../../Source/IKUNProtos/proto/ --cpp_out=../../Source/IKUNProtos/Public/ Test.proto

:: /r��ʾ�Զ�������Ŀ¼��%%i��ʾ����һ��i��in ()��ʾ������Ŀ¼��%VCPKG_ROOT%�ǻ���������
:: for /r %%i in (../../Source/IKUNProtos/proto/*.proto) do (
:: 	 %VCPKG_ROOT%/packages/protobuf_x64-windows/tools/protobuf/protoc.exe --cpp_out=../../../Source/IKUNProtos/Public/ --proto_path=../../Source/IKUNProtos/proto/%%~ni.proto
:: 	 pause
:: )
:: echo %VCPKG_ROOT%
:: /s��ʾ������Ŀ¼��/y��ʾ����ʾ�Ƿ񸲸������ļ�
:: xcopy ../../Source/IKUNProtos/Public/*.cc ../../Source/IKUNProtos/Private/ /S /E /Y

pause