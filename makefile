GPP = g++ -O3
M = main.o
P = printVector.o
F = findKeyLength.o
L = findKeyLetter.o
D = decrypt.o
T = translateLetters.o
S = Scanner.o
U = Utils.o



vigenere: $(M) $(S) $(U) $(P) $(F) $(L) $(D) $(T)
	$(GPP) -o vigenere $(M) $(S) $(U) $(P) $(F) $(L) $(D) $(T)

main.o: main.h main.cpp
	$(GPP) -o main.o -c -DEBUG main.cpp

printVector.o: printVector.h printVector.cpp
	$(GPP) -o printVector.o -c printVector.cpp

findKeyLength.o: findKeyLength.h findKeyLength.cpp
	$(GPP) -o findKeyLength.o -c findKeyLength.cpp

findKeyLetter.o: findKeyLetter.h findKeyLetter.cpp
	$(GPP) -o findKeyLetter.o -c findKeyLetter.cpp

decrypt.o: decrypt.h decrypt.cpp
		$(GPP) -o decrypt.o -c decrypt.cpp

translateLetters.o: translateLetters.h translateLetters.cpp
		$(GPP) -o translateLetters.o -c translateLetters.cpp

Scanner.o: Utilities/Scanner.h Utilities/Scanner.cpp
	$(GPP) -o Scanner.o -c Utilities/Scanner.cpp

Utils.o: Utilities/Utils.h Utilities/Utils.cpp
	$(GPP) -o Utils.o -c Utilities/Utils.cpp


clean:
	rm vigenere *.o
