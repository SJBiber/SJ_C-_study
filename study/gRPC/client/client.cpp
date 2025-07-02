// client/client.cpp
#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "hello.grpc.pb.h"
#include <chrono>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hello::Greeter;
using hello::HelloRequest;
using hello::HelloReply;
using namespace std;

class GreeterClient {
public:
  GreeterClient(std::shared_ptr<Channel> channel)
    : stub_(Greeter::NewStub(channel)) {}

  std::string SayHello(const std::string& name) {
    HelloRequest request;
    request.set_name(name);

    HelloReply reply;
    ClientContext context;

    Status status = stub_->SayHello(&context, request, &reply);
    if (status.ok()) {
      return reply.message();
    } else {
      return "RPC failed: " + status.error_message();
    }
  }

private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main() {
  while(1)
  {
    GreeterClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    string response = client.SayHello("BeaSeungJae");
    cout << "Greeter received: " << response << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}