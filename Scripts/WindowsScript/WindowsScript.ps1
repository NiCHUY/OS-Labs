    # Number
	g++ -c -o Number\Number.o Number\Number.cpp
	ar rvs Number\Number.lib Number\Number.o
	
	# Vector
	g++ -c -DVECTOR_EXPORTS -o Dll\Vector.o -INumber\ DllVector\MyVector.cpp
	g++ -shared -o Vector\Vector.dll Vector\Vector.o Number\Number.lib
	
    # Main
	g++ -o WindowsScript -INumber\ -IVector\ Sourse.cpp -L.\Number\ -L.\Vector\ -lNumber -lVector

    .\WindowsScript.exe