#!/bin/bash
while :
do
	lsof -p $1 | awk '{printf "%s\t%s\t%s\n", $4, $5, $9}'
	sleep 5
done
