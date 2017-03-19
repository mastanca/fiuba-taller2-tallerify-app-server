FROM mastanca/fiuba-tallerify-cpp:latest
ADD . fiuba-taller2-tallerify-app-server
ARG COVERALLS_SERVICE_NAME=dummy
ARG COVERALLS_SERVICE_NAME=false
ENV COVERALLS_REPO_TOKEN=$COVERALLS_REPO_TOKEN
ENV COVERALLS_SERVICE_NAME=$COVERALLS_SERVICE_NAME

WORKDIR fiuba-taller2-tallerify-app-server
RUN lcov --directory . --zerocounter
WORKDIR build
RUN $HOME/usr/bin/cmake -DCOVERALLS=ON -DCMAKE_BUILD_TYPE=Debug ..
RUN make
RUN make coveralls

#RUN if [ "$TRAVIS_BUILD" = true ]; then cd .. && \
#    bash coverage.sh; fi

CMD ["./fiuba_taller2_tallerify_app_server_test"]
