#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
PID=$(ps u | grep -E '[.]/minishell' | awk '{print $2}' | xargs echo )
IFS=' ' read -r -a pids <<< "${PID}"
for element in "${pids[@]}"
do
	echo $element
done

