if { set -C; 2>/dev/null >~/manlocktest.lock; }; then
    trap "rm -f ~/manlocktest.lock" EXIT
else
    echo "Lock file exists… exiting"
    exit
fi

while true
do
    number=$(grep  -Eo '^[0-9]+$' test.txt | tail -1)
    echo -e $((number+1)) >> test.txt
done

# Critical region occures when both 
# scripts try to modify the file.
# You never know which one will open file,
# which one will read, append and close first.
