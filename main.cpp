/*

.___________..______          ___       _______  _______  __    ______         _______..__   __.  __   _______  _______  _______ .______      
|           ||   _  \        /   \     |   ____||   ____||  |  /      |       /       ||  \ |  | |  | |   ____||   ____||   ____||   _  \     
`---|  |----`|  |_)  |      /  ^  \    |  |__   |  |__   |  | |  ,----'      |   (----`|   \|  | |  | |  |__   |  |__   |  |__   |  |_)  |    
    |  |     |      /      /  /_\  \   |   __|  |   __|  |  | |  |            \   \    |  . `  | |  | |   __|  |   __|  |   __|  |      /     
    |  |     |  |\  \----./  _____  \  |  |     |  |     |  | |  `----.   .----)   |   |  |\   | |  | |  |     |  |     |  |____ |  |\  \----.
    |__|     | _| `._____/__/     \__\ |__|     |__|     |__|  \______|   |_______/    |__| \__| |__| |__|     |__|     |_______|| _| `._____|


?Traffic Sniffer


*/


#include <iostream>
#include <tins/tins.h>

using namespace Tins;

class PacketProcessor {
public:
    virtual void process_packet(const PDU& pdu) const = 0;
    virtual ~PacketProcessor() = default;
};

class EthernetPacketProcessor : public PacketProcessor {
public:
    void process_packet(const PDU& pdu) const override {
        const EthernetII& eth = pdu.rfind_pdu<EthernetII>();
        std::cout << "Received Ethernet II packet: " << eth.src_addr() << " -> " << eth.dst_addr() << std::endl;
    }
};

class TCPPacketProcessor : public PacketProcessor {
    public:
        void process_packet(const PDU& pdu) const override {
            const TCP& tcp = pdu.rfind_pdu<TCP>();
            const IP& ip = pdu.rfind_pdu<IP>();
            std::cout << "Received TCP packet from " << ip.src_addr() << ":" << tcp.sport() << " to " << ip.dst_addr() << ":" << tcp.dport() << std::endl;
        }
};

class UDPPacketProcessor : public PacketProcessor {
    public:
        void process_packet(const PDU& pdu) const override {
            const UDP& udp = pdu.rfind_pdu<UDP>();
            const IP& ip = pdu.rfind_pdu<IP>();
            std::cout << "Received UDP packet from " << ip.src_addr() << ":" << udp.sport() << " to " << ip.dst_addr() << ":" << udp.dport() << std::endl;
        }
};

int main() {
    Sniffer sniffer("eth0");

    sniffer.sniff_loop([&](PDU& pdu) {
        switch (pdu.pdu_type()) {
            case PDU::ETHERNET_II: {
                EthernetPacketProcessor ethernetProcessor;
                ethernetProcessor.process_packet(pdu);
                break;
            }
            case PDU::TCP: {
                TCPPacketProcessor tcpProcessor;
                tcpProcessor.process_packet(pdu);
                break;
            }
            case PDU::UDP: {
                UDPPacketProcessor udpProcessor;
                udpProcessor.process_packet(pdu);
                break;
            }
            default: {
                std::cout << "Received a packet of unknown type" << std::endl;
                break;
            }
        }
        return 1; 
    });

    return 0;
}