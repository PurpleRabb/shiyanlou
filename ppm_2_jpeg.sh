#!/bin/sh
flist=`ls *.ppm`

for f in $flist
do
	file=`echo ${f%.*}`
	ffmpeg -i "$file".ppm "$file".jpg
done

mkdir -p jpgs
mv *.jpg jpgs
rm *.ppm
