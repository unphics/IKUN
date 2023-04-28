#include "PBMgr.h"

UPBMgr::UPBMgr() {
	UE_LOG(LogTemp, Display, TEXT("========== UPBMgr Constructor =========="));
	SearchRequest sr;
	sr.set_page_number(666);
	sr.set_query("qqqqqqqqq");
	FString str = sr.query().c_str();
	UE_LOG(LogTemp, Display, TEXT("log pb: num = %d, str = %s"), sr.page_number(), *str);

	this->p = &sr;
}
/*
const google::protobuf::Descriptor* UPBMgr::FindMsgDescriptor(const std::string& TypeName) {
	return google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(TypeName);
}
const google::protobuf::Message* UPBMgr::FindMsgPrototype(const std::string& TypeName) {
	const google::protobuf::Message* msg = nullptr;
	const auto desc = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(TypeName);
	if(desc) {
		msg = google::protobuf::MessageFactory::generated_factory()->GetPrototype(desc);
	}
	return msg;
}
template<typename T>
T* UPBMgr::PBNew(const std::string& TypeName) {
	// const google::protobuf::Message* msg = nullptr;
	const google::protobuf::Descriptor* desc = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(TypeName);
	if (desc) {
		const google::protobuf::Message* protoType = google::protobuf::MessageFactory::generated_factory()->GetPrototype(desc);
		if (protoType) {
			return protoType->New();
		}
	}
	return nullptr;
}
*/