#include <drogon/drogon.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpClient.h>
#include <json/config.h>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <json/writer.h>
#include <functional>
#include <print>

using Callback = std::function< void ( const drogon::HttpResponsePtr& ) >;

int main()
{
    auto& app = drogon::app();
    app.addListener("127.0.0.1", 8080);
    app.registerHandler("/", [](const drogon::HttpRequestPtr& req, Callback&& callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        Json::FastWriter writer;
        Json::Reader reader;
        Json::Value value;
        value["message"] = "Hello World! Diogo";
        auto json_str = writer.write(value);
        auto json_reader = reader.parse(json_str, value);
        if (json_reader) {
            std::println("JSON parsed successfully");
        } else {
            std::println("JSON parsed failed");
        }
        resp->setBody(json_str);
        callback(resp);
    });

    // Leave the server running indefinitely
    std::println("Server started on localhost:8080");
    app.run();

    return 0;
}
