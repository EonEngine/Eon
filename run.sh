mkdir -p build
cd build
if [ -f "Makefile" ]
then
  echo "~ Starting Build ~"
else
  cmake ..
  echo "~ Starting Build ~"
fi
make -j8 && ./Sandbox
