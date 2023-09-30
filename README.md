# Traffic Analyzer

Traffic Analyzer is a simple C++ program that uses the libtins library to capture and analyze network traffic. It can process Ethernet II, TCP, and UDP packets, displaying relevant information about each packet.

## Prerequisites

- C++11 or later
- [libtins](https://libtins.github.io/)

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/Maksikos-ctrl/TrafficAnalyzer.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd TrafficAnalyzer
    ```

3. **Build the executable:**

    ```bash
    make
    ```

4. **Run the program (requires sudo for network access):**

    ```bash
    sudo ./packet_sniffer
    ```

## Usage

The program listens to network traffic on the specified interface and processes packets based on their types (Ethernet II, TCP, UDP). The processed information is displayed on the console.

## Packet Processing

The program processes packets based on their type:

- **Ethernet II**: Displays source and destination MAC addresses.
- **TCP**: Displays source and destination IP addresses and ports.
- **UDP**: Displays source and destination IP addresses and ports.

## Contributing

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/new-feature`.
3. Make your changes and commit them: `git commit -m 'Add a new feature'`.
4. Push to the branch: `git push origin feature/new-feature`.
5. Submit a pull request.


## License

This project is licensed under the ANSYS License - see the [LICENSE](https://www.ansys.com/academic/students) file for details.