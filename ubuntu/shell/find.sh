#!/bin/bash
echo " $0 $1 $# ";

project_path=$(cd `dirname $0`; pwd)
echo $project_path
for file in `find $project_path`;
do
 echo $file
done


