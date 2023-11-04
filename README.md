# TaskManager

TaskManager is a simple command-line utility designed to provide information about the CPU and memory usage on a Linux system. This program extracts and displays essential system information from the `/proc/cpuinfo` and `/proc/meminfo` files.

## Features

- Retrieves and displays CPU information, including the model name, vendor ID, and CPU family.
- Fetches and presents memory-related data, such as total memory, free memory, available memory, and memory usage percentage.
- Issues a warning if the memory usage exceeds 85%.

## Usage

The program is straightforward to use. Upon execution, it displays the gathered CPU and memory information in a readable format. It offers insights into the current state of the system's resources, enabling users to monitor the CPU and memory usage efficiently.

## How to Run

To run the program, simply compile the source code and execute the resulting binary. Make sure to have the necessary permissions to access the `/proc` directory, which is required to read CPU and memory information.

## Credits

This program was developed by alicesys.
