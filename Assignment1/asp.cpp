// asp.cpp

#include "asp.h"

template<int T>
void asp::my_asp()
{	
	// set busy to true, since ASP is working.
	// set res_ready to false, since the output 
	// data is not ready.
	Res_ready.write(false);
	busy.write(true);



	// check is the input data is valid, and
	// operate functions depends on the opcode

	if (valid) {
		opcode = Data_in >> 22;
		memsel = (Data_in >> 17) & 1;
		if (opcode == 0000){
			store0();
		}else if (opcode == 0001){
			store1();
		}else if (opcode == 0010){
			InvokeASPXOR_A();
		}else if (opcode == 0011){
			InvokeASPXOR_B();
		}else if (opcode == 0100){
			InvokeASPMAC();
		}else if (opcode == 0101){
			InvokeASPAVE_A();
		}else if (opcode == 0110){
			InvokeASPAVE_B();
		}else{
			store0();
		}
	}
}

template<int T>
void store0(){
	if (memsel){
		for (i = 0; i < T; i++){
			B[i] = 0;
		}
		Res_ready = 1;
	}else{
		for (i = 0; i < T; i++){
			A[i] = 0;
		}
		Res_ready = 1;
	}
}

template<int T>
void store1(){

}

template<int T>
void InvokeASPXOR_A(){

}

template<int T>
void InvokeASPXOR_B(){

}

template<int T>
void InvokeASPMAC(){

}

template<int T>
void InvokeASPAVE_A(){

}

template<int T>
void InvokeASPAVE_B(){

}