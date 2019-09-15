#include <iostream>
#include "Utilitis.h"
#include "ServerFactory.h"
#include <vector>
#include <thread>
#include <future>

void initUtilitis(char **argv);
void createConnection(char **argv);

ProtocolType TYPE;

int main(int argc, char **argv) {
    try {
        if (argc != 7) {
            std::cout << "please enter: <type>  <IP> <port> <num of servers> <num of clients> <size of message>\n";
            return -1;
        }
        else {
            initUtilitis(argv);
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
    std::vector<std::shared_ptr<Server>> servers;
    std::vector<std::thread> threads;
    
    int port = atoi (argv[3]);

    for (int i = 0; i < atoi(argv[4]); ++i) {
        servers.emplace_back(ServerFactory::getServer(TYPE, argv[2], port++, atoi(argv[4]), atoi(argv[5]), atoi(argv[6])));
        threads.emplace_back(std::thread(&AbstractServer::run, servers.back()));
       
    }
    for (int j = 0; j < atoi(argv[4]); ++j) {
        if(threads.back().joinable())
            threads.back().join();
    }
    

    std::packaged_task<void()> task([](){std::cin.get();});
    std::future<void> result = task.get_future();

    std::cout << "Press any key to exit\n";

    std::thread task_td(std::move(task));
    result.wait();
    task_td.join();

}