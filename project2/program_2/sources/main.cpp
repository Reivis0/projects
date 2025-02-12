#include"client.h"
#include "outputData.h"

int main()
{
    Client client("127.0.0.1", 52000);
    client.run(&OutputData::processAndOutput);
    return 0;
}