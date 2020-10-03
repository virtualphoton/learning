for file in $(find . -name "*.cpp"); do cp $file ./; done

for file in $(find . -maxdepth 1 -name "*.cpp"); do git add $file; done

