head -n 24 libft.h > temp.h
cat *.c | grep "ft_" | grep "(" | grep -v ";" | grep -v "static" | grep -v "if" | grep -v "while" | sed 's/$/;/' >> temp.h
echo "\n#endif" >> temp.h
mv temp.h libft.h
