package rpcService

import (
	"context"
	"log"
	"net"
	"time"

	service "github.com/ryepropgroup/protoServer/protos"
	messages "github.com/ryepropgroup/protoServer/protos/messages"
	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
)

type server struct {
	service.UnimplementedEngineComputerServer
	commandChan chan *messages.SequenceCommand
	statusChan  chan *messages.SensorData
}

func NewServer(commandChan chan *messages.SequenceCommand, statusChan chan *messages.SensorData) *server {
	return &server{
		commandChan: commandChan,
		statusChan:  statusChan,
	}
}

func (s *server) SensorDataStream(stream service.EngineComputer_SensorDataStreamServer) error {
	for {
		data, err := stream.Recv()
		if err != nil {
			if err == context.Canceled {
				return nil
			}
			log.Printf("Error receiving sensor data: %v", err)
			return err
		}

		// Forward sensor data to TCP clients
		s.statusChan <- data
	}
}

func (s *server) CommandStream(info *messages.DeviceInformation, stream service.EngineComputer_CommandStreamServer) error {
	for {
		stream.Send(&messages.SequenceCommand{Sequence: "ignition"})
		time.Sleep(10 * time.Second)
	}
	// for cmd := range s.commandChan {
	// 	if err := stream.Send(cmd); err != nil {
	// 		log.Printf("Error sending command: %v", err)
	// 		return err
	// 	}
	// }
	// return nil
}

func StartGRPCServer(commandChan chan *messages.SequenceCommand, statusChan chan *messages.SensorData) {
	lis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatalf("Failed to listen: %v", err)
	}
	grpcServer := grpc.NewServer()
	service.RegisterEngineComputerServer(grpcServer, NewServer(commandChan, statusChan))
	reflection.Register(grpcServer)

	log.Println("gRPC server listening on :50051")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}