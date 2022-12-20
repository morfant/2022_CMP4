#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi

