# Tallerify's app server
App server for tallerify in C++, using mongoose and mongodb

branch | Travis CI | Coveralls
------ | --------- | --------
`master` | [![Build Status](https://travis-ci.org/tallerify/fiuba-taller2-tallerify-app-server.svg?branch=master)](https://travis-ci.org/tallerify/fiuba-taller2-tallerify-app-server) | [![Coverage Status](https://coveralls.io/repos/github/tallerify/fiuba-taller2-tallerify-app-server/badge.svg?branch=HEAD)](https://coveralls.io/github/tallerify/fiuba-taller2-tallerify-app-server?branch=HEAD)
`develop` | [![Build Status](https://travis-ci.org/tallerify/fiuba-taller2-tallerify-app-server.svg?branch=develop)](https://travis-ci.org/tallerify/fiuba-taller2-tallerify-app-server) | [![Coverage Status](https://coveralls.io/repos/github/tallerify/fiuba-taller2-tallerify-app-server/badge.svg?branch=HEAD)](https://coveralls.io/github/tallerify/fiuba-taller2-tallerify-app-server?branch=HEAD)

### Docs
You can find the docs by opening `doc/index.html` with your favorite browser \
\
To get the HEAD version of them you need doxygen and sphinx. Then run

```bash
doxygen
sphinx-build . doc/ 
```

### Running

To run you only need docker

```bash
docker-compose build
docker-compose up
```


### API

See the wiki for api references