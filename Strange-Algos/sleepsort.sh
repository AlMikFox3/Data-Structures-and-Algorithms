#Works for positive integers only
#Usage:  ./sleepsort.sh 1 2 4 5 4 29 9

function f() {
	sleep "$1"
	echo "$1"
}

while [ -n "$1" ]
do
	f "$1" &
	shift
done
wait 