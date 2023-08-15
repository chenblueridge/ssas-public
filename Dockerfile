FROM ubuntu:22.04
COPY . /usr/src/ssas
RUN apt update && apt upgrade -y
RUN apt install -y unzip wget git gcc diffutils libncurses-dev gperf curl make cmake automake unrar pkg-config binutils python3-protobuf scons python3-serial pybind11-dev python3-pil python3-ply python3-bitarray g++ vim tmux uuid-dev
#pygt5 
RUN curl -Lo protoc.zip "https://github.com/protocolbuffers/protobuf/releases/download/v24.0/protoc-24.0-linux-x86_64.zip" && unzip -q protoc.zip bin/protoc -d /usr/local && chmod a+x /usr/local/bin/protoc
WORKDIR /usr/src/ssas
