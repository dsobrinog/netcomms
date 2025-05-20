FROM ubuntu:25.04

ARG DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]

# Install build tools
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
        gdb \
        pkg-config \
        libzmq3-dev \
        git && \
    rm -rf /var/lib/apt/lists/*

# Default command
CMD [ "bash" ]

# Set working directory
WORKDIR /workspace
