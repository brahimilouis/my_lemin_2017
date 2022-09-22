#!/bin/sh
cd ..
make re > bonjour
rm bonjour
cd test
echo "--------test1---------"
../lem_in < anthill > res
echo "diff number 1"
diff res res_ant
echo "--------test2---------"
../lem_in < anthill2 > res2
echo "diff number 2"
diff res2 res_ant2
echo "---------end----------"
rm res
rm res2

