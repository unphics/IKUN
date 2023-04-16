#include "UObject/Object.h"
#include "google/protobuf/message.h"
#include "PBMgr.generated.h"
UCLASS()
class IKUNPROTOS_API UPBMgr : public UObject{
	GENERATED_BODY()
public:
	UPBMgr();
	const google::protobuf::Descriptor* FindMsgDescriptor(const std::string& TypeName);
	const google::protobuf::Message* FindMsgPrototype(const std::string& TypeName);
	template<typename T>
	T* PBNew(const std::string& TypeName);
};


