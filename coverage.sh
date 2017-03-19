#!/usr/bin/env bash

#find . -name "*.gcno" | while read line ; do
#  gcda=`echo $line | sed 's/\.gcno$/.gcda/'` ;
#  if [ \! -e $gcda ]  ; then
#    touch $gcda && echo created empty $gcda;
#  fi ;
#done

#lcov --directory ../ --capture --output-file coverage.info
#lcov --remove coverage.info '/test/*' 'build/ext/*' '/usr/*' --output-file coverage.info
#lcov --list coverage.info

#coveralls-lcov --repo-token ${COVERALLS_TOKEN} coverage.info