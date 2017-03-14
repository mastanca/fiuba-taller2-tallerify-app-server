#!/usr/bin/env bash

sudo apt-get install -y lcov
mkdir $HOME/usr
export PATH="$HOME/usr/bin:$PATH"
wget https://cmake.org/files/v3.6/cmake-3.6.3-Linux-x86_64.sh --no-check-certificate
chmod +x cmake-3.6.3-Linux-x86_64.sh
./cmake-3.6.3-Linux-x86_64.sh --prefix=$HOME/usr --exclude-subdir --skip-license
gem install coveralls-lcov
cd ${TRAVIS_BUILD_DIR}
lcov --directory . --zerocounters
mkdir build
cd build
cmake ..
make

find . -name "*.gcno" | while read line ; do
  gcda=`echo $line | sed 's/\.gcno$/.gcda/'` ;
  if [ \! -e $gcda ]  ; then
    touch $gcda && echo created empty $gcda;
  fi ;
done

make test
cd ${TRAVIS_BUILD_DIR}
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '/test/*' 'build/ext/*' '/usr/*' --output-file coverage.info
lcov --list coverage.info
coveralls-lcov --repo-token ${COVERALLS_TOKEN} coverage.info
