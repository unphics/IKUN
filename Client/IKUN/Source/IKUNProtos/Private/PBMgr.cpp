#include "PBMgr.h"
#include "Test.pb.h"

UPBMgr::UPBMgr() {
	SearchRequest sr;
	sr.set_page_number(666);
	sr.set_query("qqqqqqqqq");
	FString str = sr.query().c_str();

	UE_LOG(LogTemp, Display, TEXT("========== num: %d, str:%s"), sr.page_number(), *str);
}
