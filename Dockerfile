FROM mastanca/fiuba-tallerify-cpp:latest
ADD . fiuba-taller2-tallerify-app-server
ARG coveralls_token=dummy
ARG travis_build=false
ENV COVERALLS_REPO_TOKEN=$coveralls_token
ENV COVERALLS_SERVICE_NAME=$travis_build

WORKDIR fiuba-taller2-tallerify-app-server
RUN lcov --directory . --zerocounter
WORKDIR build
RUN $HOME/usr/bin/cmake -DCOVERALLS=ON -DCMAKE_BUILD_TYPE=Debug ..
RUN make
RUN make coveralls

#RUN if [ "$TRAVIS_BUILD" = true ]; then cd .. && \
#    bash coverage.sh; fi

CMD ["./fiuba_taller2_tallerify_app_server_test"]
