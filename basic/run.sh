for ((i=0;;i++))
do
    echo "$i"
    python3 gen.py > input
    ./ans < input > ans.out
    ./a.out < input > b.out
    diff ans.out b.out || break
done