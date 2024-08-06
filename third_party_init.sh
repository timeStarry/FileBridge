#/usr/bin/bash
for dir in $(grep 'submodule' .gitmodules | awk -F '"' '{print $2}');
do
    module=$(ls $dir)
    if [ -n $module ]; then
        echo -e "start to init third party" $dir;
        git submodule update --init --recursive;
        break;
    fi
done;