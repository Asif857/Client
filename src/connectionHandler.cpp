#include "../include/connectionHandler.h"
#include <boost/lexical_cast.hpp>
#include "../include/encoderDecoder.h"
#include "../include/bidiProtocol.h"
using boost::asio::ip::tcp;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
 
ConnectionHandler::ConnectionHandler(string host, short port, encoderDecoder encDec, bidiProtocol protocol): host_(host), port_(port), io_service_(), socket_(io_service_), encDec_(encDec), protocol_(protocol){}
    
ConnectionHandler::~ConnectionHandler() {
    close();
}
 
bool ConnectionHandler::connect() {
    std::cout << "Starting connect to " 
        << host_ << ":" << port_ << std::endl;
    try {
		tcp::endpoint endpoint(boost::asio::ip::address::from_string(host_), port_); // the server endpoint
		boost::system::error_code error;
		socket_.connect(endpoint, error);
		if (error)
			throw boost::system::system_error(error);
    }
    catch (std::exception& e) {
        std::cerr << "Connection failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    return true;
}
 
bool ConnectionHandler::getBytes(char bytes[], unsigned int bytesToRead) {
    size_t tmp = 0;
	boost::system::error_code error;
    try {
        while (!error && bytesToRead > tmp ) {
			tmp += socket_.read_some(boost::asio::buffer(bytes+tmp, bytesToRead-tmp), error);			
        }
		if(error)
			throw boost::system::system_error(error);
    } catch (std::exception& e) {
        std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    return true;
}

bool ConnectionHandler::sendBytes(const char bytes[], int bytesToWrite,  const char bytesArr[]) {
    int tmp = 0;
	boost::system::error_code error;
    try {
        while (!error && bytesToWrite > tmp ) {
			tmp += socket_.write_some(boost::asio::buffer(bytes + tmp, bytesToWrite - tmp), error);
        }
		if(error)
			throw boost::system::system_error(error);
    } catch (std::exception& e) {
        std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    return true;
}
 
bool ConnectionHandler::getLine(std::vector<char> bytes) {
    return getFrameAscii(bytes,';');
}

bool ConnectionHandler::sendLine(std::string& line) {
    return sendFrameAscii(line, ';');
}
 
bool ConnectionHandler::getFrameAscii(std::vector<char> bytes,char delimiter) {
    char ch;
    // Stop when we encounter the null character. 
    // Notice that the null character is not appended to the frame string.
    try {
		do{
			getBytes(&ch, 1);
            bytes.push_back(ch);
        }while (delimiter != ch);
    } catch (std::exception& e) {
        std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    protocol_.process(encDec_.decode(bytes));
    return true;
}
 
bool ConnectionHandler::sendFrameAscii(const std::string& frame, char delimiter) {
    std::string opcode;
    std::string updateFrame;
    opcode.append(std::to_string(frame.at(0)));
    if(frame.at(0) == '1' && frame.at(1) == '2'){
        opcode.append(std::to_string(frame.at(1)));
        updateFrame = frame.substr(2);
    }
    else{
        updateFrame = frame.substr(1);
    }
    std::stringstream strOpcode(opcode);
    short shortOpcode;
    strOpcode >>shortOpcode;
    char bytes[2];
    encDec_.shortToBytes(shortOpcode, bytes);
	bool result=sendBytes(frame.c_str(),frame.length(), bytes);
	if(!result) return false;
	return sendBytes(&delimiter,1);
}
 
// Close down the connection properly.
void ConnectionHandler::close() {
    try{
        socket_.close();
    } catch (...) {
        std::cout << "closing failed: connection already closed" << std::endl;
    }
}

encoderDecoder ConnectionHandler::getEncDec() const {
    return encDec_;
}

bidiProtocol ConnectionHandler::getProtocol() const {
    return protocol_;
}
