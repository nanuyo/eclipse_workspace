cpp-example-train_HOG -t -fn=my_detector.yml -td=/home/hjpark/Pictures/HOG_train/eggs-test
cpp-example-train_HOG -d -dw=64 -dh=64 -pd=../../eggs-pos -nd=../../eggs-neg -td=../../eggs-test
./HOG_Train -d -dw=64 -dh=64 -pd=/home/hjpark/Pictures/HOG_train/eggs-pos -nd=/home/hjpark/Pictures/HOG_train/eggs-neg -td=/home/hjpark/Pictures/HOG_train/eggs-test
./HOG_Train -t -fn=my_detector.yml -td=/home/hjpark/Pictures/HOG_train/eggs-test
./HOG_Train -t -fn=my_detector.yml -td=/home/hjpark/Pictures


./HOG_Train -d -dw=64 -dh=64 -pd=/home/hjpark/Pictures/HOG_train/pos -nd=/home/hjpark/Pictures/HOG_train/neg -td=/home/hjpark/Pictures/HOG_train/test