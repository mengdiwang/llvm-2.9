../../Release+Asserts+Checks/bin/opt -load ../../Release+Asserts+Checks/lib/CEPass.so -cefinder -debug <prod-cons.bc > /dev/null
#../../Release+Asserts+Checks/bin/opt -load ../../Release+Asserts+Checks/lib/CEPass.dylib -cefinder -debug <tcas.bc > /dev/null
dot -Tpng funcs.dot > funcs.png
dot -Tpng blocks.dot > blocks.png
echo "Critical Edges results:"
echo "[Target] (Func funcid choice branchline)"
cat ce-block-dump.out
