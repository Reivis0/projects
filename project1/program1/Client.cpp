#include"Client.h"

void client::connection(const std::string &msg)
{
    char buf[sizeof(msg)];
    int  sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
        throw(std::runtime_error(ERROR_OF_CONNECTION));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
          throw(std::runtime_error(ERROR_OF_CONNECTION));

    send(sock, msg.c_str(), sizeof(msg),0);
    close(sock);
}