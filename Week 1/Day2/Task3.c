echo -n "Max element:"
cat numbers.txt | sort -n -r | head -n 1
echo  -n "Min element:"
cat numbers.txt | sort -n | head -n 1