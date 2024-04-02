rm p5_tests/*.s ;

for entry in p5_tests/*.java; do
    test -e "$entry" && echo "$entry";
    ./codegen "$entry";
done
