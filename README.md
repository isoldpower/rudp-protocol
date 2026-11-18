# Hybrid Transfer Protocol (HTP) Project
The idea of the project is to implement the transport protocol sitting purely at Layer 4 of OSI model.
It means the project shouldn't use UDP or TCP or any other implemented transport layer underneath and should implement 
its own rules for safely transferring data. It should also define multilanguage protocol message bindings and
multilanguage implementations of client/server over the transport protocol.

## How it is useful
Specific features of the protocol and what makes it different from UDP or TCP is that it is a hybrid between them,
and is mostly used for unreliable delivery but with possibility to route important messages over safe ordered message
channel

### Usage example
As an example of where this protocol may be useful we can imagine an online game where players can move and reach
checkpoints. Player movement is a frequent event that doesn't require accuracy (unless its a competitive game) but
player reaching the checkpoint is an important one-of event that needs to be consistent and is fine to be delayed
by a moment to ensure safe delivery.

## Folder Structure
The folder structure in the project is trying to achieve three things:
1) Encapsulated and split the logic across multiple targets;
2) Make it obvious for the reader where the entrypoint is and which other libraries does every library import;
3) Provide convenient and intuitive namespaces and import paths;

Thus, the project is organized as a set of libraries that each import others from top to bottom. 
It creates clear layer segregation and changing libraries deeper in the hierarchy will influence those 
that are higher in directory tree.

```bash
nikitalapin@mac rudp-protocol % tree -I "build"
.
├── CMakeLists.txt
├── executables                                     # All executables are stored here, as well as exec-specific logic
│   ├── CMakeLists.txt                              #
│   └── main.cpp                                    #
├── external                                        # External libraries fetch & linkage, such as GTest or Boost
│   └── CMakeLists.txt                              #
├── README.md                                       #
└── rudp_protocol                                   # Root of app-related targets
    ├── CMakeLists.txt                              #
    ├── python_bindings                             # All *_bindings libraries are language-specific bindings
    ├── rudp_library                                # All protocol-related targets are stored under this dir
    │   ├── api_layer                               # Creates C API boundary on top of C++ implementation
    │   │   ├── CMakeLists.txt                      #
    │   │   ├── include                             #
    │   │   │   └── rudp_library                    #
    │   │   │       └── api_layer                   #
    │   │   │           └── placeholder.h           #
    │   │   └── src                                 #
    │   │       └── rudp_library                    #
    │   │           └── api_layer                   #
    │   │               └── placeholder.cpp         #
    │   ├── CMakeLists.txt                          # 
    │   ├── core                                    # Core instructions. Decides what to give for transport
    │   │   ├── CMakeLists.txt                      # 
    │   │   ├── include                             # include/ directory follows the namespaces to make import
    │   │   │   └── rudp_library                    #   paths look intuitive and easy to read
    │   │   │       └── core                        #
    │   │   │           └── placeholder.hpp         #
    │   │   └── src                                 # src/ directory structure mirrors include/ directory structure
    │   │       └── rudp_library                    #   to improve DX and make it easier to pair
    │   │           └── core                        #   definition with implementation
    │   │               └── placeholder.cpp         #
    │   ├── platform                                #
    │   │   ├── CMakeLists.txt                      #
    │   │   ├── env_checks                          # Checks that run to get report on environemnt accessibility
    │   │   │   ├── CMakeLists.txt                  #
    │   │   │   ├── include                         #
    │   │   │   │   └── rudp_library                #
    │   │   │   │       └── platform                #
    │   │   │   │           └── env_checks          #
    │   │   │   │               └── placeholder.hpp #
    │   │   │   └── src                             #
    │   │   │       └── rudp_library                #
    │   │   │           └── platform                #
    │   │   │               └── env_checks          #
    │   │   │                   └── placeholder.cpp #
    │   │   └── io                                  # Different environments links (for example, LAN, IP, etc.)
    │   │       ├── CMakeLists.txt                  #
    │   │       ├── include                         #
    │   │       │   └── rudp_library                #
    │   │       │       └── platform                #
    │   │       │           └── io                  #
    │   │       │               └── placeholder.hpp #
    │   │       └── src                             #
    │   │           └── rudp_library                #
    │   │               └── platform                #
    │   │                   └── io                  #
    │   │                       └── placeholder.cpp #
    │   └── transport                               # Wiring layer of C++ transport instructions to work together
    │       ├── CMakeLists.txt                      #
    │       ├── include                             #
    │       │   └── rudp_library                    #
    │       │       └── transport                   #
    │       │           └── placeholder.hpp         #
    │       └── src                                 #
    │           └── rudp_library                    #
    │               └── transport                   #
    │                   └── placeholder.cpp         #
    └── rust_bindings                               # Rust-specific bindings for the transport protocol
```
