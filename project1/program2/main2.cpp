#include "Strings.h"
#include"Buffer.h"
#include<thread>
#include<exception>
#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>
#pragma warning(disable:4996)

void putInTheBuffer(Buffer &buffer);
void extractFromTheBuffer(Buffer& buffer);
void connection(const int res);

const std::string ERROR_OF_CONNECTION = "Error of connection\n";

int main()
{
	try
	{
		Buffer buffer;
		std::thread th1(putInTheBuffer, std::ref(buffer));
		std::thread th2(extractFromTheBuffer, std::ref(buffer));
		th1.join();
		th2.join();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void putInTheBuffer(Buffer& buffer)
{
	while (true)
	{
		Strings str;

		std::cin >> str;
		if (std::cin.eof()) break;
		if (std::cin.fail())
		{
			std::cin.clear();
			continue;
		}
		str.transformation();
		buffer.push(str);
	}
	buffer.setEndStatus();
}

void extractFromTheBuffer(Buffer &buffer)
{
		while (!buffer.getEndStatus() || !buffer.getEmpty())
		{
			while (!buffer.getEmpty())
			{
				Strings str = buffer.pop();
				std::cout << str << std::endl;;

				int sum = str.sum_of_elements();

				connection(sum);
			}
		}
		connection(-1);
}


void connection(const int res)
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) throw(std::runtime_error(ERROR_OF_CONNECTION));
	SOCKADDR_IN addr;
	int size_of_addr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, size_of_addr);
	listen(sListen, SOMAXCONN);

	SOCKET new_connection;
	new_connection = accept(sListen, (SOCKADDR*)&addr, &size_of_addr);
	if (new_connection == 0) throw(std::runtime_error(ERROR_OF_CONNECTION));
	else
	{
		char msg[256];
		std::strcpy(msg, std::to_string(res).c_str());
		send(new_connection, msg, sizeof(msg), NULL);
		closesocket(new_connection);
	}
	closesocket(sListen);
	WSACleanup();
}