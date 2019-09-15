//
// Created by talya on 20/08/2019.
//

#ifndef BENCHMARK_MASSAGE_H
#define BENCHMARK_MASSAGE_H

#include <string>

class Massage {
public:
    Massage(int size);
    std::string get() { return m_massage; }
private:
    std::string m_massage;
};





#endif //BENCHMARK_MASSAGE_H
