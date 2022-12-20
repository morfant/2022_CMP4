#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  make -f /Users/giy/MTK/CMP4/SC/perlinnoise/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  make -f /Users/giy/MTK/CMP4/SC/perlinnoise/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  make -f /Users/giy/MTK/CMP4/SC/perlinnoise/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/giy/MTK/CMP4/SC/perlinnoise/build
  make -f /Users/giy/MTK/CMP4/SC/perlinnoise/build/CMakeScripts/ReRunCMake.make
fi

