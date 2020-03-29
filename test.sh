echo $1;
echo $2;
search_size=$1
total=$2

for thread in {1,2,4,8}
do
		echo 
		for var in {1..5}
		do
			./main $search_size $total $thread
		done
	
done