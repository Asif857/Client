all: SPL3new

SPL3new: bin/bidiClient.o bin/bidiProtocol.o bin/connectionHandler.o bin/encoderDecoder.o bin/Task.o
		@echo 'Linking files'
		g++ -o bin/bidiClient.o bin/bidiProtocol.o bin/connectionHandler.o bin/encoderDecoder.o bin/Task.o

bin/bidiClient.o: src/bidiClient.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/bidiClient.o src/bidiClient.cpp

bin/bidiProtocol.o: src/bidiProtocol.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/bidiProtocol.o src/bidiProtocol.cpp

bin/connectionHandler.o: src/connectionHandler.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/connectionHandler.o src/connectionHandler.cpp

bin/encoderDecoder.o: src/encoderDecoder.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/encoderDecoder.o src/encoderDecoder.cpp

bin/Task.o: src/Task.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Task.o src/Task.cpp

clean:
		@echo 'Cleaning'
		rm -f bin/*