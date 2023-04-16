#include "helper.h"

const google::protobuf::Descriptor* IKUNProtos::FindMsgDescriptor(const std::string& TypeName) {
    return google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(TypeName);
    //return nullptr;
}

const google::protobuf::Message* IKUNProtos::FindMsgPrototype(const std::string& TypeName) {

	const google::protobuf::Message* Factory = nullptr;
	const auto Desc = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(TypeName);
	if (Desc) {
		// Calling this method twice with the same Descriptor returns the same object.
		Factory = google::protobuf::MessageFactory::generated_factory()->GetPrototype(Desc);
	}

	return Factory;
}
