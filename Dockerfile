FROM ubuntu:latest
RUN apt-get update -y

RUN apt-get install -y lcov
RUN apt-get install -y git
RUN apt-get install -y build-essential checkinstall
RUN apt-get install -y wget
RUN apt-get install -y rubygems ruby-dev

#RUN mkdir $HOME/usr
#RUN export PATH="$HOME/usr/bin:$PATH"
#RUN wget https://cmake.org/files/v3.6/cmake-3.6.3-Linux-x86_64.sh --no-check-certificate
#RUN chmod +x cmake-3.6.3-Linux-x86_64.sh
#RUN sh cmake-3.6.3-Linux-x86_64.sh --prefix=$HOME/usr --exclude-subdir --skip-license
RUN apt-get install -y cmake
RUN gem install coveralls-lcov

RUN git clone https://github.com/mastanca/fiuba-taller2-tallerify-app-server.git && cd fiuba-taller2-tallerify-app-server
RUN lcov --directory . --zerocounter

RUN mkdir build
RUN cd build
RUN cmake ..
RUN make
RUN make test

RUN cd ..
RUN chmod +x coverage.sh
RUN sh coverage.sh
