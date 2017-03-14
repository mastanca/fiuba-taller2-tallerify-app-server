FROM mastanca/fiuba-tallerify-cpp:latest
ADD . fiuba-taller2-tallerify-app-server
ARG coveralls_token=dummy
ARG travis_build=false
ENV COVERALLS_TOKEN=$coveralls_token
ENV TRAVIS_BUILD=$travis_build

WORKDIR fiuba-taller2-tallerify-app-server
RUN lcov --directory . --zerocounter
WORKDIR build
RUN $HOME/usr/bin/cmake ..
RUN make
RUN make test
