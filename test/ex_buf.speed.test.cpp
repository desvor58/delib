#include "../src/exbuf.hpp"

int main()
{
    time_t start;

    de::ExBuf<int> buf(512);

    time(&start);
    for (long i = 0; i < 100000; i++) {
        buf.push_back(i);
    }

    for (long i = 0; i < 100000; i++) {
        if (buf[i] != i) {
            return 1;
            std::cerr << "ERROR" << std::endl;
        }
    }
    time_t end;
    time(&end);
    std::cout << "ALL GOOD" << std::endl;

    std::cout << "de::ExBuf time: "
              << (double)(end - start)
              << std::endl;

    // vector
    std::vector<int> vbuf;

    time(&start);
    for (long i = 0; i < 100000; i++) {
        vbuf.push_back(i);
    }

    for (long i = 0; i < 100000; i++) {
        if (vbuf[i] != i) {
            return 1;
            std::cerr << "ERROR" << std::endl;
        }
    }
    time(&end);
    std::cout << "ALL GOOD" << std::endl;
    std::cout << "std::vector time: "
              << end - start
              << std::endl;

    return 0;
}