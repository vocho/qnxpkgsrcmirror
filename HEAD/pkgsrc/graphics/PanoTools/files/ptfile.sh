#!/bin/sh
#
#	$Id: ptfile.sh 147690 2007-01-03 15:01:08Z seanb $
#
export CLASSPATH=@@prefix@@/share/PanoTools:${CLASSPATH}
export JAVA_HOME=@@javahome@@
export PATH=$JAVA_HOME/bin:$PATH
@@prefix@@/bin/mkpthelpers
ulimit -d `ulimit -d -H`
ulimit -s `ulimit -s -H`
ulimit -m `ulimit -m -H`
ulimit -p `ulimit -p -H`
ulimit -n `ulimit -n -H`
exec java -jar @@prefix@@/share/PanoTools/@@ptfile@@.jar "$@"
