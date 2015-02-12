echo "********************************************************"
echo "testing multable"
echo "********************************************************"
python ~cs537-1/testing/p1a/multable/MulttableTest.py multable/
echo "********************************************************"
echo "testing tnine"
echo "********************************************************" 
python ~cs537-1/testing/p1a/tnine/KeyPadTest.py tnine/ 
echo "********************************************************"
echo "testing submission"
echo "********************************************************"
cd multable
python /u/c/s/cs537-1/testing/p1a/tnine/KeyPadTest.py 
cd ../tnine
python ~cs537-1/testing/p1a/multable/MulttableTest.py 
echo "********************************************************"
echo "done"
echo "********************************************************"
