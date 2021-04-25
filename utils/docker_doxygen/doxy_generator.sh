#! /bin/bash

echo "+--------------------+"
echo "*******Start**********"
echo "+--------------------+"

DIR_DOXY=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
DIR_PROJ=$( cd "$( dirname "${DIR_DOXY}/../../../" )" && pwd )

docker build -t doxy_img .
docker run -it -v ${DIR_PROJ}:/gomoku/ --name doxy1 doxy_img 
docker run --rm --volume ${DIR_PROJ}:/gomoku -w=/gomoku doxy_img doxygen Doxyfile

echo "+--------------------+"
echo "********Done**********"
echo "+--------------------+"