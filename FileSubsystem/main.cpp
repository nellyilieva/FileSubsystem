#include <iostream>
#include "Runner.h"

int main() {
    try {
        run();
    }
    catch (std::runtime_error& exc) {
        std::cout << "Invalid argument: " << exc.what() << std::endl;
    }
    catch (std::exception& exc) {
        std::cout << "Error: " << exc.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown error occurred." << std::endl;
    }
    return 0;
}