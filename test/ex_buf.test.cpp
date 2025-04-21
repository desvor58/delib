#include "../src/exbuf.hpp"

int main()
{
    de::ExBuf<int> buf(5);

    buf.push_back(1);
    buf.push_back(2);
    buf.push_back(3);
    buf.push_back(4);
    buf.push_back(5);

    for (int i = 0; i < buf.size(); i++) {
        std::cout << buf[i] << std::endl;
    }
    std::cout << std::endl;
    buf.erace(2);
    for (int i = 0; i < buf.size(); i++) {
        std::cout << buf[i] << std::endl;
    }
    std::cout << std::endl;

    buf.push_back(69);
    
    for (int i = 0; i < buf.size(); i++) {
        std::cout << buf[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << buf.size() << std::endl;
    std::cout << buf.alocated_size() << std::endl;
}