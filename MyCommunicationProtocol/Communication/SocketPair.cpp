#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#include "CommunicationChannel.h"

class SocketPair : public CommunicationChannel {
    private:
        int channel[2];
    public:
        SocketPair() {
            socketpair(AF_UNIX, SOCK_STREAM, 0, channel);
        }

        void Read(char* subject, int readLimit = 255) {
            read(channel[1], subject, readLimit);
        }

        void Write(const char* subject, int bitsLength) {
            write(channel[1], subject, bitsLength); 
        }

        void CloseReadDescriptors() {
            close(channel[0]);
        }

        void CloseWriteDescriptors() {
            close(channel[1]);
        }

};