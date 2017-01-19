cmake_minimum_required(VERSION 3.6)
project(Client)
message(STATUS "start running cmake...")
set(CMAKE_CXX_STANDARD 11  )
find_package(Boost 1.57.0 COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(Client include/Builders/AckCommandBuilder.h include/Builders/BroadcastCommandBuilder.h include/Builders/CommandBuilder.h include/Builders/DataCommandBuilder.h include/Builders/TFTPErrorCommandBuilder.h include/Commands/Ack.h include/Commands/Broadcast.h include/Commands/Command.h include/Commands/Data.h include/Commands/DeleteRequest.h include/Commands/DirlistRequest.h include/Commands/DisconnectRequest.h include/Commands/LoginRequest.h include/Commands/ReadRequest.h include/Commands/Response.h include/Commands/TFTPError.h include/Commands/WriteRequest.h include/EncDec/ShortEncoderDecoder.h include/EncDec/StringEncoderDecoder.h include/EncDec/TFTPEncoderDecoder.h
        src/Builders/AckCommandBuilder.cpp src/Builders/BroadcastCommandBuilder.cpp src/Builders/DataCommandBuilder.cpp src/Builders/TFTPErrorCommandBuilder.cpp src/Commands/Ack.cpp src/Commands/Broadcast.cpp src/Commands/Data.cpp src/Commands/DeleteRequest.cpp src/Commands/DirlistRequest.cpp src/Commands/DisconnectRequest.cpp src/Commands/LoginRequest.cpp src/Commands/ReadRequest.cpp src/Commands/TFTPError.cpp src/Commands/WriteRequest.cpp src/EncDec/ShortEncoderDecoder.cpp src/EncDec/StringEncoderDecoder.cpp src/EncDec/TFTPEncoderDecoder.cpp
        include/Encoders/AckCommandEncoder.h include/Encoders/CommandEncoder.h include/Encoders/DataCommandEncoder.h include/Encoders/EncoderUtils.h include/Encoders/TFTPErrorEncoder.h
        src/Encoders/AckCommandEncoder.cpp src/Encoders/DataCommandEncoder.cpp src/Encoders/EncoderUtils.cpp src/Encoders/TFTPErrorEncoder.cpp
        include/connectionHandler.h src/connectionHandler.cpp src/echoClient.cpp src/ClientReceiver.cpp include/ClientReceiver.h src/Builders/CommandBuilderFactory.cpp include/Builders/CommandBuilderFactory.h src/Encoders/CommandEncoderFactory.cpp include/Encoders/CommandEncoderFactory.h src/Encoders/DirlistCommandEncoder.cpp include/Encoders/DirlistCommandEncoder.h src/Encoders/LoginCommandEncoder.cpp include/Encoders/LoginCommandEncoder.h src/Encoders/DeleteCommandEncoder.cpp include/Encoders/DeleteCommandEncoder.h)
target_link_libraries(Client ${Boost_LIBRARIES})
