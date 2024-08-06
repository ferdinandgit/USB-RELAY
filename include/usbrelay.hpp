
#pragma once
#include <serialib.hpp>
#include <memory>
#include <string>
#include <vector>
#include <bitset>



using std::string;




class Usbrelay
{

public:
    
    Usbrelay(const string& port,int relaynumber = 8);
    int openCom();  
    int closeCom();
    int  initBoard();
    int setState(int*);
    int setState(int);
    char getState();
    char getrx();
    int getSpeed();
    std::string getPort();
    int getRelayNumber();
    int setPort(const std::string &port);
    
private:

    int send(char  data, unsigned long milliseconds);
    int recieve(int nbyte);
    void bufferrxAdd(char elt);
    void buffertxAdd(char elt);
    int baudrate;
    int relaynumber;
    std::string device; 
    std::vector<char> buffertx =  std::vector<char>(8);
    std::vector<char> bufferrx =  std::vector<char>(8);
    std::unique_ptr<serialib> boardinterface;
    
};

std::vector<std::string> scanBoard();
std::bitset<8> charToBitset(char);
void os_sleep(unsigned long);