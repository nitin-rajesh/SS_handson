#! /bin/zsh
priority=0
if [[ "$#" == "1" ]]; then
    priority=$1
fi
echo "Setting priority" $priority
gcc loop.c -o loop
nice -n $priority ./loop &
pidval=`pgrep loop`
ps -l -p $pidval