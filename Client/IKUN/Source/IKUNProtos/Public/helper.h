#pragma once
//#include <google/protobuf/message>
#include "google/protobuf/message.h"

namespace IKUNProtos {
	IKUNPROTOS_API const google::protobuf::Descriptor* FindMsgDescriptor(const std::string& TypeName);
	IKUNPROTOS_API const google::protobuf::Message* FindMsgPrototype(const std::string& TypeName);
}