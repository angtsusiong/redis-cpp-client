#include <hiredis/hiredis.h>
#include <iostream>

int main(int argc, char **argv) {
    redisContext *c;
    redisReply *reply;
    freeReplyObject(reply);
    reply = static_cast<redisReply*>(redisCommand(c, "JSON.GET animal $"));
    std::cout << reply->str << std::endl;
}