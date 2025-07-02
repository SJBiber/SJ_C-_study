#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "hello.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using hello::Greeter;
using hello::HelloRequest;
using hello::HelloReply;

class GreeterServiceImpl final : 
public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::string prefix("Hello SKrr ~ ");
    reply->set_message(prefix + request->name());
    std::cout << "Server Recive!!" << std::endl;
    return Status::OK;
  }
};

void RunServer() {
  std::string address("0.0.0.0:50051");
  GreeterServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << address << std::endl;
  server->Wait();
}

int main() {
  RunServer();
  return 0;
}