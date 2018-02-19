#!/bin/sh

pid=`ps aux | grep highpropertyserver|awk '{print $2;exit(1)}'`

echo ${pid}

kill -9 ${pid}
