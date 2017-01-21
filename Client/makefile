CC=g++
CFLAGS=-g -Wall -Weffc++ -std=c++11 -c -Iinclude
LDFLAGS:=-lboost_system -lboost_locale -lboost_filesystem -lboost_thread

all:TFTPclient

TFTPclient: bin/AckCommandBuilder.o bin/BroadcastCommandBuilder.o bin/DataCommandBuilder.o bin/TFTPErrorCommandBuilder.o bin/Ack.o bin/Broadcast.o bin/Data.o bin/DeleteRequest.o bin/DirlistRequest.o bin/DisconnectRequest.o bin/LoginRequest.o bin/ReadRequest.o bin/TFTPError.o bin/WriteRequest.o bin/ShortEncoderDecoder.o bin/StringEncoderDecoder.o bin/TFTPEncoderDecoder.o bin/AckCommandEncoder.o bin/DataCommandEncoder.o bin/EncoderUtils.o bin/TFTPErrorEncoder.o bin/connectionHandler.o bin/echoClient.o bin/CommandBuilderFactory.o bin/CommandEncoderFactory.o bin/DirlistCommandEncoder.o bin/LoginCommandEncoder.o bin/DeleteCommandEncoder.o bin/DisconnectCommandEncoder.o bin/WriteCommandEncoder.o bin/ReadCommandEncoder.o bin/Protocol.o
	$(CC)	bin/AckCommandBuilder.o bin/BroadcastCommandBuilder.o bin/DataCommandBuilder.o bin/TFTPErrorCommandBuilder.o bin/Ack.o bin/Broadcast.o bin/Data.o bin/DeleteRequest.o bin/DirlistRequest.o bin/DisconnectRequest.o bin/LoginRequest.o bin/ReadRequest.o bin/TFTPError.o bin/WriteRequest.o bin/ShortEncoderDecoder.o bin/StringEncoderDecoder.o bin/TFTPEncoderDecoder.o bin/AckCommandEncoder.o bin/DataCommandEncoder.o bin/EncoderUtils.o bin/TFTPErrorEncoder.o bin/connectionHandler.o bin/echoClient.o bin/CommandBuilderFactory.o bin/CommandEncoderFactory.o bin/DirlistCommandEncoder.o bin/LoginCommandEncoder.o bin/DeleteCommandEncoder.o bin/DisconnectCommandEncoder.o bin/WriteCommandEncoder.o bin/ReadCommandEncoder.o bin/Protocol.o -o bin/TFTPclient $(LDFLAGS)
bin/AckCommandBuilder.o: src/Builders/AckCommandBuilder.cpp include/Builders/AckCommandBuilder.h
	$(CC) $(CFLAGS) -o bin/AckCommandBuilder.o src/Builders/AckCommandBuilder.cpp

bin/BroadcastCommandBuilder.o: src/Builders/BroadcastCommandBuilder.cpp include/Builders/BroadcastCommandBuilder.h
	$(CC) $(CFLAGS) -o bin/BroadcastCommandBuilder.o src/Builders/BroadcastCommandBuilder.cpp

bin/DataCommandBuilder.o: src/Builders/DataCommandBuilder.cpp include/Builders/DataCommandBuilder.h
	$(CC) $(CFLAGS) -o bin/DataCommandBuilder.o src/Builders/DataCommandBuilder.cpp

bin/TFTPErrorCommandBuilder.o: src/Builders/TFTPErrorCommandBuilder.cpp include/Builders/TFTPErrorCommandBuilder.h
	$(CC) $(CFLAGS) -o bin/TFTPErrorCommandBuilder.o src/Builders/TFTPErrorCommandBuilder.cpp

bin/Ack.o: src/Commands/Ack.cpp include/Commands/Ack.h
	$(CC) $(CFLAGS) -o bin/Ack.o src/Commands/Ack.cpp

bin/Broadcast.o: src/Commands/Broadcast.cpp include/Commands/Broadcast.h
	$(CC) $(CFLAGS) -o bin/Broadcast.o src/Commands/Broadcast.cpp

bin/Data.o: src/Commands/Data.cpp include/Commands/Data.h
	$(CC) $(CFLAGS) -o bin/Data.o src/Commands/Data.cpp

bin/DeleteRequest.o: src/Commands/DeleteRequest.cpp include/Commands/DeleteRequest.h
	$(CC) $(CFLAGS) -o bin/DeleteRequest.o src/Commands/DeleteRequest.cpp

bin/DirlistRequest.o: src/Commands/DirlistRequest.cpp include/Commands/DirlistRequest.h
	$(CC) $(CFLAGS) -o bin/DirlistRequest.o src/Commands/DirlistRequest.cpp

bin/DisconnectRequest.o: src/Commands/DisconnectRequest.cpp include/Commands/DisconnectRequest.h
	$(CC) $(CFLAGS) -o bin/DisconnectRequest.o src/Commands/DisconnectRequest.cpp

bin/LoginRequest.o: src/Commands/LoginRequest.cpp include/Commands/LoginRequest.h
	$(CC) $(CFLAGS) -o bin/LoginRequest.o src/Commands/LoginRequest.cpp

bin/ReadRequest.o: src/Commands/ReadRequest.cpp include/Commands/ReadRequest.h
	$(CC) $(CFLAGS) -o bin/ReadRequest.o src/Commands/ReadRequest.cpp

bin/TFTPError.o: src/Commands/TFTPError.cpp include/Commands/TFTPError.h
	$(CC) $(CFLAGS) -o bin/TFTPError.o src/Commands/TFTPError.cpp

bin/WriteRequest.o: src/Commands/WriteRequest.cpp include/Commands/WriteRequest.h
	$(CC) $(CFLAGS) -o bin/WriteRequest.o src/Commands/WriteRequest.cpp

bin/ShortEncoderDecoder.o: src/EncDec/ShortEncoderDecoder.cpp include/EncDec/ShortEncoderDecoder.h
	$(CC) $(CFLAGS) -o bin/ShortEncoderDecoder.o src/EncDec/ShortEncoderDecoder.cpp

bin/StringEncoderDecoder.o: src/EncDec/StringEncoderDecoder.cpp include/EncDec/StringEncoderDecoder.h
	$(CC) $(CFLAGS) -o bin/StringEncoderDecoder.o src/EncDec/StringEncoderDecoder.cpp

bin/TFTPEncoderDecoder.o: src/EncDec/TFTPEncoderDecoder.cpp include/EncDec/TFTPEncoderDecoder.h
	$(CC) $(CFLAGS) -o bin/TFTPEncoderDecoder.o src/EncDec/TFTPEncoderDecoder.cpp

bin/AckCommandEncoder.o: src/Encoders/AckCommandEncoder.cpp include/Encoders/AckCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/AckCommandEncoder.o src/Encoders/AckCommandEncoder.cpp

bin/DataCommandEncoder.o: src/Encoders/DataCommandEncoder.cpp include/Encoders/DataCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/DataCommandEncoder.o src/Encoders/DataCommandEncoder.cpp

bin/EncoderUtils.o: src/Encoders/EncoderUtils.cpp include/Encoders/EncoderUtils.h
	$(CC) $(CFLAGS) -o bin/EncoderUtils.o src/Encoders/EncoderUtils.cpp

bin/TFTPErrorEncoder.o: src/Encoders/TFTPErrorEncoder.cpp include/Encoders/TFTPErrorEncoder.h
	$(CC) $(CFLAGS) -o bin/TFTPErrorEncoder.o src/Encoders/TFTPErrorEncoder.cpp

bin/connectionHandler.o: src/connectionHandler.cpp include/connectionHandler.h
	$(CC) $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/echoClient.o: src/echoClient.cpp
	$(CC) $(CFLAGS) -o bin/echoClient.o src/echoClient.cpp

bin/CommandBuilderFactory.o: src/Builders/CommandBuilderFactory.cpp include/Builders/CommandBuilderFactory.h
	$(CC) $(CFLAGS) -o bin/CommandBuilderFactory.o src/Builders/CommandBuilderFactory.cpp

bin/CommandEncoderFactory.o: src/Encoders/CommandEncoderFactory.cpp include/Encoders/CommandEncoderFactory.h
	$(CC) $(CFLAGS) -o bin/CommandEncoderFactory.o src/Encoders/CommandEncoderFactory.cpp

bin/DirlistCommandEncoder.o: src/Encoders/DirlistCommandEncoder.cpp include/Encoders/DirlistCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/DirlistCommandEncoder.o src/Encoders/DirlistCommandEncoder.cpp

bin/LoginCommandEncoder.o: src/Encoders/LoginCommandEncoder.cpp include/Encoders/LoginCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/LoginCommandEncoder.o src/Encoders/LoginCommandEncoder.cpp

bin/DeleteCommandEncoder.o: src/Encoders/DeleteCommandEncoder.cpp include/Encoders/DeleteCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/DeleteCommandEncoder.o src/Encoders/DeleteCommandEncoder.cpp

bin/DisconnectCommandEncoder.o: src/Encoders/DisconnectCommandEncoder.cpp include/Encoders/DisconnectCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/DisconnectCommandEncoder.o src/Encoders/DisconnectCommandEncoder.cpp

bin/WriteCommandEncoder.o: src/Encoders/WriteCommandEncoder.cpp include/Encoders/WriteCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/WriteCommandEncoder.o src/Encoders/WriteCommandEncoder.cpp

bin/ReadCommandEncoder.o: src/Encoders/ReadCommandEncoder.cpp include/Encoders/ReadCommandEncoder.h
	$(CC) $(CFLAGS) -o bin/ReadCommandEncoder.o src/Encoders/ReadCommandEncoder.cpp

bin/Protocol.o: src/Protocol.cpp include/Protocol.h
	$(CC) $(CFLAGS) -o bin/Protocol.o src/Protocol.cpp


clean:
	rm -rf bin/*o bin/TFTPclient
