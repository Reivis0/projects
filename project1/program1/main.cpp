#include<iostream>
#include<exception>
#include<string>
#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>

#pragma warning(disable:4996)

const std::string ERROR_OF_VALUE = "Ircorrect value\n";
const std::string ERROR_OF_CONNECTION = "Error of connection\n";

void isCorrectValue(const int value);
int connection();

int main()
{
	int value = connection();
	try 
	{
		while (value != -1)
		{
			try
			{
				isCorrectValue(value);
				value = connection();
			}
			catch (std::exception& ex) 
			{ 
				std::cerr << ex.what();
				value = connection();
				continue;
			}
		}
	}
	catch (std::exception& ex) 
	{
		std::cerr << ex.what(); 
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void isCorrectValue(const int value)
{
	if (value / 100 > 0 && value % 32 == 0) std::cout << value << std::endl;
	else throw(std::out_of_range(ERROR_OF_VALUE)); 
}

int connection()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) throw(std::runtime_error(ERROR_OF_CONNECTION));
	SOCKADDR_IN addr;
	int size_of_addr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET connectionSocket = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connectionSocket, (SOCKADDR*)&addr, size_of_addr) != 0)
	{
		closesocket(connectionSocket);
		WSACleanup();
		Sleep(5000);
		return connection();
	}

	char res[256];
	recv(connectionSocket, res, sizeof(res), NULL);
	int value = std::stoi(res);
	closesocket(connectionSocket);
	WSACleanup();
	return value;

}