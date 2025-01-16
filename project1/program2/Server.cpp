#include"Server.h"

void server::connection()
{
    int value;
    int  sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0)
        throw(std::runtime_error(ERROR_OF_CONNECTION));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (bind(listener, (struct sockaddr *)&addr,sizeof(addr) ) < 0)
        throw(std::runtime_error(ERROR_OF_CONNECTION));

    listen(listener,1);
    while(1)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
            throw(std::runtime_error(ERROR_OF_CONNECTION));
        
        while(1)
        {
            bytes_read = recv(sock, buf, 1024, 0);
            if (bytes_read <= 0)
                break;
            value = std::stoi(buf);
          try
          {
            isCorrectValue(value);
            if (buf=="-1")
            {
                 close(sock);
                 close(listener);
                 return;
            }
          }
          catch(const std::out_of_range& e)
          {
            std::cerr << e.what() << '\n';
            continue;
          }
          
        }
        close(sock);
       
    }
    close(listener);
}
