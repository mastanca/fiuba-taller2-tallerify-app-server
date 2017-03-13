FROM ubuntu:latest
ENV COVERALLS_TOKEN=$COVERALLS_TOKEN
RUN apt-get update -y

RUN apt-get install -y lcov
RUN apt-get install -y git
RUN apt-get install -y build-essential checkinstall
RUN apt-get install -y wget
RUN apt-get install -y rubygems ruby-dev

RUN gem install coveralls-lcov

WORKDIR fiuba-taller2-tallerify-app-server
RUN lcov --directory . --zerocounter
RUN ls -l

WORKDIR build
RUN mkdir $HOME/usr && \
    export PATH="$HOME/usr/bin:$PATH" && \
    wget https://cmake.org/files/v3.6/cmake-3.6.3-Linux-x86_64.sh --no-check-certificate && \
    chmod +x cmake-3.6.3-Linux-x86_64.sh && \
    sh cmake-3.6.3-Linux-x86_64.sh --prefix=$HOME/usr --exclude-subdir --skip-license && \
    cmake ..
RUN make
RUN make test

RUN cd .. && \
    chmod +x coverage.sh && \
    sh coverage.sh
