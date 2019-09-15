#include <iostream>
#include "Utilitis.h"
#include "ClientFactory.h"
#include <thread>
#include <vector>
#include <future>


void initUtilitis(char **argv);
void createConnection(char ** argv);

ProtocolType TYPE;


int main(int argc, char **argv) {
    try {
        if (argc != 7) {
            std::cout << "please enter: <type> <port> <num of servers> <num of clients> <size of message>\n";
            return -1;
        }
        else {
            initUtilitis(argv);//start the clients running after initilize the utiitis needed
            createConnection(argv);
        }
    }
    catch (std::exception& e)
    {
        std::printf("Exception: %s\n", e.what());
    }
}

void initUtilitis(char **argv)
{
    switch (*argv[1])
    {
        case 't':
            TYPE = TCP;
            break;
        case 'r':
            TYPE = RPC;
            break;
        case 'l':
            TYPE = LIBUV;
            break;
        case 'a':
            TYPE = ASIO;
            break;
    }
}

void createConnection(char **argv)
{
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::thread> threads;

    int s = atoi(argv[4]);
    int port = atoi(argv[3]);


    for (int i = 0; i < atoi(argv[5]); ++i) {
        clients.emplace_back(ClientFactory::getClient(TYPE, argv[2], port++, atoi(argv[4]), atoi(argv[5]), atoi(argv[6])));
        threads.emplace_back(std::thread(&AbstractClient::run, clients.back()));

        if(port == atoi(argv[3]) + s)
            port = atoi(argv[3]);
    }

    for (int i = 0; i < atoi(argv[5]); ++i) {
        if (threads.back().joinable())
            threads.back().join();
    }



    std::packaged_task<void()> task([](){std::cin.get();});
    std::future<void> result = task.get_future();

    std::cout << "Press any key to exit\n";

    std::thread task_td(std::move(task));
    result.wait();
    task_td.join();

}