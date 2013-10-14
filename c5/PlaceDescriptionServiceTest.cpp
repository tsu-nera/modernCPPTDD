#include "gmock/gmock.h"
#include "PlaceDescriptionService.h"
#include "Http.h"

using namespace std;
using namespace testing;

// Google Mock 生成
class HttpStub: public Http {
public:
   MOCK_METHOD0(initialize, void());
   MOCK_CONST_METHOD1(get, string(const string&));
};

// テストスイート
class APlaceDescriptionService: public Test {
public:
  static const string ValidLatitude;
  static const string ValidLongitude;

  shared_ptr<HttpStub> httpStub;
  shared_ptr<HttpFactory> factory;
  shared_ptr<PlaceDescriptionService> service;

  virtual void SetUp() override {
    factory = make_shared<HttpFactory>();
    service = make_shared<PlaceDescriptionService>(factory);
  }

  void TearDown() override {
    factory.reset();
    httpStub.reset();
  }
};

// テストスイートの継承がデキるのか！これは発見
class APlaceDescriptionService_WithHttpMock: public APlaceDescriptionService {
public:
  void SetUp() override {
    APlaceDescriptionService::SetUp(); // ここで継承
    httpStub = make_shared<HttpStub>();
    factory->setInstance(httpStub);
  }
};

TEST_F(APlaceDescriptionService_WithHttpMock, MakesHttpRequestToObtainAddress) {
  string urlStart{
    "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
   auto expectedURL = urlStart + 
     "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
     "lon=" + APlaceDescriptionService::ValidLongitude;
   EXPECT_CALL(*httpStub, initialize());
   EXPECT_CALL(*httpStub, get(expectedURL));

   service->summaryDescription(ValidLatitude, ValidLongitude);
}

class APlaceDescriptionService_WithNiceHttpMock: public APlaceDescriptionService {
public:
  void SetUp() override {
    APlaceDescriptionService::SetUp(); // ここで継承
    httpStub = make_shared<NiceMock<HttpStub>>();
    factory->setInstance(httpStub);
  }
};

TEST_F(APlaceDescriptionService_WithNiceHttpMock,
       FormatsRetrievedAddressIntoSummaryDescription) {
  EXPECT_CALL(*httpStub, get(_))
    .WillOnce(Return(
         R"({ "address": {
              "road":"Drury Ln",
              "city":"Fountain",
              "state":"CO",
              "country":"US" }})"));

  auto description = service->summaryDescription(ValidLatitude, ValidLongitude);

  Mock::VerifyAndClearExpectations(httpStub.get());
  ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}

const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");
