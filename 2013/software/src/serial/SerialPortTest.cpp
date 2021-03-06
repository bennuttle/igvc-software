//============================================================================
// Name        : SerialPortTest.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>

#include "ASIOSerialPort.h"
#include <iostream>

using namespace std;

class LinePrinter {
public:
    LinePrinter(ASIOSerialPort *port)
        : LonNewLine(this)
    {
        port->onNewLine += &LonNewLine;
    }

    void onNewLine(string line) {
        cout << line << endl;
    }

    LISTENER(LinePrinter, onNewLine, string);
};

int main() {
	std::cout << "Testing serial API..." << std::endl;
	ASIOSerialPort serialPort("/dev/ttyUSB0", 9600);

	LinePrinter printer(&serialPort);
	serialPort.startEvents();

	for(int i=0; i < 6; i++) {
		serialPort.write("T");
		sleep(1);
	}
//	while(true) {
//		std::cout << serialPort.readln() << std::endl;
//	}
	while(serialPort.isConnected()) { }
	serialPort.close();
}
