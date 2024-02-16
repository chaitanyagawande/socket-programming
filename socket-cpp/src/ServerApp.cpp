#include "include/BasicServer.hpp"

int main(int argc, char **argv) {
    BasicServer basicServer(2345);
    basicServer.start();
}