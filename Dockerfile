FROM mastanca/fiuba-tallerify-cpp:latest
ADD . fiuba-taller2-tallerify-app-server
ARG coveralls_token=dummy
ENV COVERALLS_TOKEN=$coveralls_token

WORKDIR fiuba-taller2-tallerify-app-server
WORKDIR build
RUN $HOME/usr/bin/cmake ..
RUN make
RUN make test
